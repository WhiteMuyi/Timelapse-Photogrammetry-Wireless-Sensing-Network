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

}


void loop()
{   

  // Take a picture!
  // We send a HIGH pulse to mosfet to turn the camera on. We wait 5 seconds until the camera is fully ready,
  delay(cmra_ready_time);
  digitalWrite(opto, HIGH);
  Serial.println("Opto!");
  // We would want to wait a while to make sure that the picture is saved and then shut the camera down to prevent
  // damaging the camera.
  delay(phto_saved_time);
  digitalWrite(opto, LOW);


}
