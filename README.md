
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
| Electronics 	| Arduio Uno| [B008GRTSV6](https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/) |  1	| Amazon|  $28.50	|
| Electronics	| DSLR Camera| [Nikon D5600](https://www.nikonusa.com/en/nikon-products/product/dslr-cameras/d5600.html) | 1 | Nikon | $669.95|
| Electronics  | PCB | [Custom TPWSNSys Printed Circuit Board](https://jlcpcb.com) 	|     1    	| JLC	|   $5.00	|
| Electronics 	| Mosfet 	| [RFP12N10L-ND](https://www.digikey.com/en/products/detail/onsemi/RFP12N10L/458764) 	| 1 	| Digikey 	|  $1.17	|
| Electronics 	| Optocoupler 	| [4N25VS-ND](https://www.digikey.com/en/products/detail/vishay-semiconductor-opto-division/4N25/1738516) 	| 1 	| Digikey 	| $0.40	|
| Electronics 	| DC/DC converter 	| [1951-2432-ND](https://www.digikey.com/en/products/detail/traco-power/TSRN-1-2490/9383467) 	| 1 	| Digikey 	|  $11.75	|
| Electronics 	| Shutter release 	| [B017O7LDCA](https://www.amazon.com/Foto-Tech-2-5mm-N3-Control-Shutter/dp/B017O7LDCA/) 	| 1 	| Amazon 	| $9.99 	|
| Electronics 	| DC coupler 	| [B071HP6F3L](https://www.amazon.com/EP-5A-Adapter-Battery-Replacement-EN-EL14a/dp/B071HP6F3L) 	| 1 	| Amazon 	| $32.99 	|
| Electronics 	| GPS 	| [GPS-13670](https://www.sparkfun.com/products/13670) 	| 1 	| Spark Fun 	|  $49.50	|
| Electronics 	| JST jumper wire 	| [PRT-10361](https://www.sparkfun.com/products/10361) 	| 1 	| Spark Fun 	|  $1.60	|
| Electronics 	| LED 	| - 	| 1 	| Lab owned 	| -	|
| Electronics 	| 1k-ohm Resistor 	| - 	| 2 	| Lab owned 	| -	|
| Electronics 	| Micro SD Adapter 	| [B01IPCAP72](https://www.amazon.com/Storage-Memory-Shield-Module-Arduino/dp/B01IPCAP72) 	| 1 | Amazon 	| $1.50	|
| Electronics 	| 2 Pin terminal block 	| [B08B3JP9QZ](https://www.amazon.com/Terminal-Block-Connector/dp/B08B3JP9QZ) 	| 3	| Amazon 	| $1.20	|
| Electronics 	| 3 Pin terminal block 	| [B08B3FPKFZ](https://www.amazon.com/Terminal-Block-Connector/dp/B08B3FPKFZ) 	| 2	| Amazon 	| $0.80	|
