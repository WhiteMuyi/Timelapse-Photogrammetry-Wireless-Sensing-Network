
# Timelapse-Photogrammetry-Wireless-Sensing-Network

<p align="center">
  <img src="https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/figure/FirstPage.jpeg" width='50%' height='50%'/>
</p>
<!--
![Image](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/figure/FirstPage.jpeg)
-->

## 1.0 Introduction
<p align="justify"> 
The Timelapse Photogrammetry Wireless Sensing Network System (TPWSNSys) is a low-cost, open source timelapse camera control system designed to capture glacier movement in extreme environments. Velocity and change in surface elevation are both critical pieces in understanding how a glacier is responding to the climate, where time-lapse cameras are being used to track glacier velocities and changes in surface elevation over time using feature-tracking and photogrammetry. The camera linked with this sensing loop can open automatically and capture photos at the scheduled times powered by solar energy. 

<p align="justify"> 
In this project, we designed a camera that can provide ground-truth data to compare with large-scale, systematic remote sensing data products. By doing this, we targeted to assess the accuracy of these global products, filter the noise, and developed methods to improve these satellite-based datasets.


## 2.0 Methods

### 2.1 Design

The Timelapse photogrammetry wireless sensing network is constructed using off-the-shelf components. This system is capable of handling iceberg recording tasks for a year or beyond. The design principles of the system show below, including:
* Inexpensive
* Off-the-shelf components
* Modular
* Power-efficient
* Open sourse
* User friendly
* Robust

#### 2.1.1 Bill of Materials
**Table 1.** Components making up version 3.0 of the TPWSNSys. Prices current as of December, 2022 and do not include taxes and/or shipping.
|   Category  	|    Component    	|  Part Number 	| Quantity 	|    Vendor   	| Price |
|:-----------:	|:---------------:	|:------------:	|:--------:	|:-----------:	|---	|
| Electronics 	| [Arduio Uno](https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/)| B008GRTSV6   	|     1    	| Amazon|  $28.50	|
|             	| DSLR Camera     	| Nikon D5600  	|     1    	| -           	|   	|
|             	| PCB          	| RFP12N10L-ND 	|     1    	| Digikey     	|   	|
|             	| Mosfet          	| RFP12N10L-ND 	|     1    	| Digikey     	|   	|
|             	| Optocoupler     	| 4N25VS-ND    	|     1    	| Digikey     	|   	|
|             	| DC/DC converter 	| 1951-2432-ND 	|     1    	| Digikey     	|   	|
|             	| Shutter release 	| B017O7LDCA   	|     1    	| Amazon      	|   	|
|             	| DC coupler      	| B071HP6F3L   	|     1    	| Amazon      	|   	|
|             	| GPS             	| GPS-13670    	|     1    	| Spark Fun   	|   	|
|             	| JST jumper wire 	| PRT-10361    	|     1    	| Spark Fun   	|   	|
|             	| LED             	| -            	|     1    	| Lab owned   	|   	|
|             	| 1k-ohm Resistor 	| -            	|     2    	| Lab owned   	|   	|
|             	| Nanuk case      	| 915-001      	|     1    	| Nanuk       	|   	|
|             	| Insulation      	| U0jtIh_T9gQ  	|     1    	| Second Skin 	|   	|
