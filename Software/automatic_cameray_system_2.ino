#include <SoftwareSerial.h>
#include <Timezone.h>
#include <TimeLib.h>
#include <SD.h>
#include <SPI.h>

// Instance declaration.
SoftwareSerial ss(2, 3);
TimeChangeRule usAKDT = {"AKDT", Second, Sun, Mar, 2, -480};  // UTC - 8 hours
TimeChangeRule usAKST = {"AKST", First, Sun, Nov, 2, -540};   //UTC - 9 hours
Timezone usAlaska(usAKDT, usAKST);
File myFile;


// Variable declaration.
// int time_span = 6;
// Pin assignment.
int gps_wake = 7;
// GPS variables.
int calibrate_time = true;
// Time zone
time_t alaska, utc;
int recalibrate_hr = 10;
int recalibrate_min = 0;
int recalibrate_sec1 = 10;
int recalibrate_sec2 = 30;
int hr_shot1 = 10;   // These three shot hours have to be arranged chronically.
int hr_shot2 = 12;
int hr_shot3 = 14;
long hour_till, minute_till, second_till;
// SD card.
int pinCS = 10;
int seq_int;
// Camera.
int opto = 8;
int mosfet = 9;
unsigned long cmra_ready_time = 5000; // 5000 milliseconds.
unsigned long phto_saved_time = 10000;  // 10000 milliseconds.



void setup()
{
  Serial.begin(9600);
  ss.begin(9600);

  // Pin assignment.
  pinMode(gps_wake, OUTPUT);
  pinMode(pinCS, OUTPUT);
  // Both opto and mosfet are set to OUTPUT. It is because we are sending pulses to the optocoupler and the mosfet.
  pinMode(opto, OUTPUT);
  pinMode(mosfet, OUTPUT);

  // Check if SD card is opened correctly.
  if(SD.begin())
  {
    Serial.println("SD card is ready to use!");
  }
  else
  {
    Serial.println("SD card initialization failed!");
  }

  // Open the the file in the SD card.
  myFile = SD.open("pic_seq.txt", FILE_WRITE);
  // Check if file is opened sucessfully.
  if(myFile)
  {
    // Check if it is an empty file, namely new SD card.
    myFile.seek(0);
    if(!myFile.available())
    {
      Serial.println("No file in the SD card!");
      seq_int = 0;
    }
    else
    {
      Serial.println("A file is found in the SD card!");
      unsigned long read_indicator = myFile.size();
      read_indicator = read_indicator - 28;
      myFile.seek(read_indicator);
      float seq = 0;
      for(int i = 0; i < 4; i++)
      { 
        float temp = pow(10, 3-i);
        float data = (myFile.read() - '0');
        seq = seq + data * temp;
      }
      seq_int = (int) round(seq);
    }
  }
  else
  {
    Serial.println("Error opening pic_seq.txt!");
  }
  // Close the opened file to ensure data is physically stored in the SD card.
  myFile.close(); 


  getTime();
  alaska = changeTimeZone();
  
  if(hour(alaska) < hr_shot1)
  {
    hour_till = hr_shot1 - (hour(alaska) % hr_shot1) - 1;
    minute_till = 60 - (minute(alaska) % 60) - 1;
    second_till = 60 - (second(alaska) % 60);
  }
  else if((hour(alaska) >= hr_shot1) && (hour(alaska) < hr_shot2))
  {
    hour_till = hr_shot2 - (hour(alaska) % hr_shot2) - 1;
    minute_till = 60 - (minute(alaska) % 60) - 1;
    second_till = 60 - (second(alaska) % 60);
  }
  else if((hour(alaska) >= hr_shot2) && (hour(alaska) < hr_shot3))
  {
    hour_till = hr_shot3 - (hour(alaska) % hr_shot3) - 1;
    minute_till = 60 - (minute(alaska) % 60) - 1;
    second_till = 60 - (second(alaska) % 60);
  }
  else
  {
    hour_till = 24 - (hour(alaska) % 24) - 1 + hr_shot1;
    minute_till = 60 - (minute(alaska) % 60) - 1;
    second_till = 60 - (second(alaska) % 60);
  }
  // Calculate delay amount (sec).
  long  delay_amount = hour_till * 3600 + minute_till * 60 + second_till;
  // Delay (input: millisecond).
  delay(delay_amount * 1000);
}


void loop()
{ 

  
  // Increase photo sequence number.
  seq_int++;
  // Open file in SD card.
  // Write to file in the SD card.
  myFile = SD.open("pic_seq.txt", FILE_WRITE);
  // Check if file is opened sucessfully.
  if(myFile)
  {
    alaska = changeTimeZone();
    char str[32];
    sprintf(str, "%04d - %02d/%02d/%02d %02d:%02d:%02d \n", seq_int, month(alaska), day(alaska) , year(alaska), hour(alaska) ,minute(alaska), second(alaska));
    myFile.write(str);

    Serial.println("Time from the library");
    Serial.print("Year: "); Serial.println(year(alaska));
    Serial.print("Month: "); Serial.println(month(alaska));
    Serial.print("Date: "); Serial.println(day(alaska));
    Serial.print("Hour: "); Serial.println(hour(alaska));
    Serial.print("Minute: "); Serial.println(minute(alaska));
    Serial.print("Second: "); Serial.println(second(alaska));
  }
  else
  {
    Serial.println("Error opening pic_seq.txt!");
  }
  // Close the opened file to ensure data is physically stored in the SD card.
  myFile.close(); 
  

  // Take a picture!
  // We send a HIGH pulse to mosfet to turn the camera on. We wait 5 seconds until the camera is fully ready,
  // and then we take a picture.
  digitalWrite(mosfet, HIGH);
  Serial.println("Mosfet!");
  delay(cmra_ready_time);
  digitalWrite(opto, HIGH);
  Serial.println("Opto!");
  // We would want to wait a while to make sure that the picture is saved and then shut the camera down to prevent
  // damaging the camera.
  delay(phto_saved_time);
  digitalWrite(opto, LOW);
  digitalWrite(mosfet, LOW);


  // Recalirbrate at designated time every day
  alaska = changeTimeZone();
  if((hour(alaska) == recalibrate_hr) && (minute(alaska) == recalibrate_min) && (second(alaska) >= recalibrate_sec1) && (second(alaska) <= recalibrate_sec2)){
    getTime();
  }

  // Calculate delay time.
  alaska = changeTimeZone();
  if(hour(alaska) < hr_shot1)
  {
    hour_till = hr_shot1 - (hour(alaska) % hr_shot1) - 1;
    minute_till = 60 - (minute(alaska) % 60) - 1;
    second_till = 60 - (second(alaska) % 60);
  }
  else if((hour(alaska) >= hr_shot1) && (hour(alaska) < hr_shot2))
  {
    hour_till = hr_shot2 - (hour(alaska) % hr_shot2) - 1;
    minute_till = 60 - (minute(alaska) % 60) - 1;
    second_till = 60 - (second(alaska) % 60);
  }
  else if((hour(alaska) >= hr_shot2) && (hour(alaska) < hr_shot3))
  {
    hour_till = hr_shot3 - (hour(alaska) % hr_shot3) - 1;
    minute_till = 60 - (minute(alaska) % 60) - 1;
    second_till = 60 - (second(alaska) % 60);
  }
  else
  {
    hour_till = 24 - (hour(alaska) % 24) - 1 + hr_shot1;
    minute_till = 60 - (minute(alaska) % 60) - 1;
    second_till = 60 - (second(alaska) % 60);
  }
  
  // Calculate delay amount (sec).
  long  delay_amount = hour_till * 3600 + minute_till * 60 + second_till;
  delay(delay_amount * 1000);
}




void getTime(){
  static const unsigned int MAX_MESSAGE_LENGTH = 60;
  bool TIME_CHECK = false;
  // Ping gps to turn it on
  digitalWrite(gps_wake, HIGH);
  // Delay 5 seconds to get rid of gibberish
  delay(10000);
  while(!TIME_CHECK){
    // Check to see if anything is available to in the serial receive buffer
    while(ss.available() > 0){
      // Create a place to hold the incoming message
      static char message[MAX_MESSAGE_LENGTH];
      static unsigned int message_pos = 0;

      // Read the next available byte in the serial reciver buffer
      char inByte = ss.read();

      // Message coming in (check not terminating character)
      if(inByte != '\n' && (message_pos < MAX_MESSAGE_LENGTH - 1)){
        // Add the coming byte to our message
        message[message_pos] = inByte;
        message_pos++;
      }
      // Full message received
      else{
        // Check if the full message is '$GPRMC,' or not
        if((message[0] == '$') && (message[1] == 'G') && (message[2] == 'P') && (message[3] == 'R') && (message[4] == 'M') && (message[5] == 'C') && (message[6] == ',')){
          Serial.println(message);
          // Check the validity of the data by looking at the status byte
          if(message[17] == 'A'){
            // Convert GPS characters into numerical values
            int hr = (int(message[7])-48)*10 + (int(message[8])-48);
            int mins = (int(message[9])-48)*10 + (int(message[10])-48);
            int secs = (int(message[11])-48)*10 + (int(message[12])-48);
            int dayy = (int(message[53])-48)*10 + (int(message[54])-48);
            int mth = (int(message[55])-48)*10 + (int(message[56])-48);
            int yr = (int(message[57])-48)*10 + (int(message[58])-48);
            setTime(hr, mins, secs, dayy, mth, yr);
            TIME_CHECK = true;
            // Turn gps off
            digitalWrite(gps_wake, LOW);
          }
        }
        message_pos = 0;
      }
    }
  }
}

// Convert time from UTC to Pittsburgh's time zone
time_t changeTimeZone(){
 utc = now();
 return usAlaska.toLocal(utc);
}
