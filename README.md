
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
| Electronics 	| LED 	| [	LN0628](https://www.amazon.com/eBoot-Pieces-Emitting-Diodes-Assorted/dp/B06XPV4CSH?th=1)	| 1 	| Amazon 	| $7.59/ 100 pieces	|
| Electronics 	| 1k-ohm Resistor 	| [13-CFR-50JR-52-1KTR](https://www.digikey.com/en/products/detail/yageo/CFR-50JR-52-1K/9099443) 	| 2 	| Digikey	| $0.22/ 2 |
| Electronics 	| Micro SD??Adapter 	| [B01IPCAP72](https://www.amazon.com/Storage-Memory-Shield-Module-Arduino/dp/B01IPCAP72) 	| 1 | Amazon 	| $1.50	|
| Electronics 	| 2 Pin terminal block 	| [B08B3JP9QZ](https://www.amazon.com/Terminal-Block-Connector/dp/B08B3JP9QZ) 	| 3	| Amazon 	| $1.20	|
| Electronics 	| 3 Pin terminal block 	| [B08B3FPKFZ](https://www.amazon.com/Terminal-Block-Connector/dp/B08B3FPKFZ) 	| 2	| Amazon 	| $0.80	|

**Table 2.** Components making up the enclosure, mounting and power systems for TPWSNSys Version 3.0.
| Category 	| Component 	| Part Number 	| Quantity 	| Vendor 	| Discription 	| Price 	|
|:---:	|:---:	|:---:	|:---:	|:---:	|---	|---	|
| Enclosure 	| Nanuk Case 	| [915-001](https://nanuk.com/products/nanuk-915) 	| 1 	| Nanuk 	|  Case to protect the system 	| $94.95	|
| Enclosure 	| Insulation 	| [U0jtIh_T9gQ](https://www.secondskinaudio.com/heat-insulation/heat-wave-pro) 	| Variable 	| Second Skin 	|   Thermal Insulation	| $79.99/24 sq ft	|
| Enclosure 	| Tripod 	| [B07FN8DJ58](https://www.amazon.com/Tri-Max-Universal-Elevator-Tripod-90558/dp/B07FN8DJ58) 	| 1 	| Amazon	|  -	| $599.98 	|
| Enclosure	| Aluminum plate 	| [9246K472](https://www.mcmaster.com/catalog/128/4070) 	| 1 	| McMaster Carr 	| Mouting   plate for the tripod. 	| $7.4/ 4''x6'' 	|
| Enclosure 	| Aluminum plate 	| [89015K233](https://www.mcmaster.com/catalog/128/4069) 	| 1 	| McMaster Carr 	| Base   place attached to the enclosure to secure the camera. 	|  $4.8/ 4''x 4''	|
| Enclosure 	| Plexiglass 	| [Recommandation](https://www.homedepot.com/b/Building-Materials-Glass-Plastic-Sheets-Plexiglass/N-5yc1vZc9x2) 	| 1 	| Home Depot 	| Plexiglass   is used for camera window. 	| $0.4/ 4''x3''	|
| Enclosure 	| Steel hex nuts 	| [95462A029](https://www.mcmaster.com/catalog/128/3497) 	| 6 	| McMaster Carr 	| 1/4''   - 20 thread size 	|  $10.93/50 pieces	|
| Enclosure 	| Steel hex screws 	| [92865A542](https://www.mcmaster.com/catalog/128/3440) 	| 8 	| McMaster Carr 	| 1/4''   - 20 thread size 	|  $13.26/100 pieces	|
| Enclosure 	| Wing nuts 	| [215175](https://www.homedepot.com/p/Everbilt-1-4-in-20-Zinc-Plated-Wing-Nut-4-Pack-802371/204274202) 	| 2 	| Home Depot 	| 1/4''   - 20 thread size 	| $1.38/ 4 pieces	|
| Enclosure 	| Washers 	| [246799](https://www.homedepot.com/p/Everbilt-1-4-in-Stainless-Steel-Flat-Washer-6-Pack-800341/204276462) 	| 6 	| Home Depot 	| 1/4''   - 20 thread size 	| $1.36/ 6 pieces	|
| Power supply 	| Battery 	| [PS-12260NB](https://www.amazon.com/Powersonic-PS-12260NB-26-0Ah-Rechargeable-Battery/dp/B000XB24SW) 	| 1 	| Battery Plus 	|  Provide energy for the whole system 	|  $71.95	|
| Power supply 	| Solar   controller 	| [SS-6](https://www.solar-electric.com/ss-6.html) 	| 1 | Northern Arizona Wind & Sun 	|  Connect solar panel and battery, keep voltage stable 	| $71.00 	|
| Power supply 	| Solar panel 	| [RNG-100D-SS-US](https://www.amazon.com/Renogy-Monocrystalline-Solar-Compact-Design/dp/B07GF5JY35) 	| 1 	| Amazon 	|   Change solar energy into electrical energy	| $84.99 	|
| Power supply 	| 12 AWG chords 	| [B074GG48F2](https://www.amazon.com/BNTECHGO-Silicone-Flexible-Strands-Stranded/dp/B01ABOPMEI/) 	| 3 	| Amazon 	| Connect between battery and solar panel	|  $12.98	|
| Power supply 	| Connection receptacle 	| [889-1000-ND](https://www.digikey.com/en/products/detail/amphenol-sine-systems-corp/AT04-2P/2125172) 	| 1 	| Digikey	| Connection receptacle, plug and socket are for the water-proof connection from solar panel to solar controller. | $0.61 	|
| Power supply 	| Connection plug 	| [889-1012-ND](https://www.digikey.com/en/products/detail/amphenol-sine-systems-corp/AT06-2S/2125184) 	| 1 	| Digikey 	| -	| $0.68	|
| Power supply 	| Connection socket 	| [889-1049-1-ND](https://www.digikey.com/en/products/detail/amphenol-sine-systems-corp/AT62-16-0122/2125221) 	| 1 	| Digikey 	| -	| $0.44 	|
| Power supply 	| Ring terminals 	| [432306](https://www.homedepot.com/p/Gardner-Bender-12-10-AWG-12-1-4-Stud-Size-Vinyl-Insulated-Ring-Terminals-Yellow-15-Pack-15-107/202522877) 	| 2 	| Home Depot 	|  Link SunSaver with Battery	|  $4.38/ 15 pieces	|
| Power supply 	| Cable gland 	| [AIO-CSM12-ND](https://www.digikey.com/en/products/detail/amphenol-industrial-operations/AIO-CSM12/3904956) 	| 2	| Digikey	| Link SunSaver with Solar Panel  	| $1.71/ 1 	|
| Miscellaneous	| Zip tie 	| [1004137721](https://www.homedepot.com/p/HDX-14-in-UV-Resist-Zip-Ties-Black-20-Pack-FT-370STUV-20/307799374) 	| Home Depot	| 3-5 	| Zip ties are used to secure the solar panel to the tripod. 	| $4.21/ 20 pieces	|
| Miscellaneous	| Electrical tape 	| [1003142024](https://www.homedepot.com/p/Scotch-Super-33-3-4-in-x-66-ft-x-0-007-in-Vinyl-Electrical-Tape-Black-6132-BA-10/304653556) 	| 1 	| Home Depot 	|  - | $8.32 	|
| Miscellaneous	| Shrink wrap 	| [B072PCQ2LW](https://www.amazon.com/560PCS-Heat-Shrink-Tubing-Eventronic/dp/B072PCQ2LW) 	| 1 	| Amazon 	| Shrink wraps prevent the exposure of soldered connections. 	|  $6.99	|
| Miscellaneous	| Gorilla epoxy 	| [757442](https://www.homedepot.com/p/Gorilla-0-85-fl-oz-Epoxy-42001/100670610) 	| 1 	| Home Depot 	| Epoxy is applied to create waterproof connections. 	| $7.48 	|
| Miscellaneous	| Dessicant 	| - 	| 1 	| - 	|  -	| -	|
| Miscellaneous	| Heat gun 	| [B078S5QMFG](https://www.amazon.com/SEEKONE-Heat-Gun-Hot-Air/dp/B078S5QMFG) 	| 1 	| Amazon 	|  Shrink wrap. 	| $28.99 |

### 2.2 Electronics' Purpose

![Image](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/figure/3D.png)


* <b>Solar Panel</b>:  <p align="justify"> Solar panels use sunlight as a source of energy to generate direct current electricity. A collection of PV modules is called a PV panel, and a system of PV panels is called an array. Arrays of a photovoltaic system supply solar electricity to electrical equipment.
  
   <p align="justify">In this system, solar panel converts solar energy into electricity to charge the battery.
   
  
* <b>Sun Saver 6</b>:  <p align="justify"> Sun Saver 6 is a 12V PWM charge controller. Pulse Width Modulation (PWM) is the most effective means to achieve constant voltage battery charging by switching the solar system controller's power devices. When in PWM regulation, the current from the solar array tapers according to the battery's condition and recharging needs. When a battery voltage reaches the regulation setpoint, the PWM algorithm slowly reduces the charging current to avoid heating and gassing of the battery, yet the charging continues to return the maximum amount of energy to the battery in the shortest time. The result is a higher charging efficiency, rapid recharging, and a healthy battery at full capacity.
   
   [Sun Saver 6 Datasheet](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/Documentation/SunSaver6-manual.pdf)
  
* <b>Power Sonic</b>: <p align="justify"> Battery. Storage electricity and provide it to future use. 
  
   [Power Sonic Datasheet](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/Documentation/datasheet-PS-12260.pdf)
   
* <b>MOSFET</b>: <p align="justify"> The function of MOSFET is to control whether the circuit is connected or not by voltage. There are two kinds of MOSFET: NMOSFET and PMOSFET.
  
  RFP12N10L is a NMOSFET. This performance is accomplished through a special gate oxide design which provides full rated conduction at gate biases in the 3V to 5V range.
  
  [Mosfet Datasheet](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/Documentation/datasheet-MOSFET-RFP12N10L.pdf)
  
* <b>DC-Converter</b>: <p align="justify"> DC-to-DC converter is an electronic circuit or electromechanical device that converts a source of direct current (DC) from one voltage level to another. It is a type of electric power converter. Power levels range from very low (small batteries) to very high (high-voltage power transmission).
  
  <p align="justify"> In this system, the DC-converter converts the voltage flowing from the battery into the pathway from 12V to 9V for use by the Arduion.
  
  [DC Converter Datasheet](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/Documentation/datasheet-tsrn1.pdf)
  
* <b>DC Coupler</b>: <p align="justify"> Enable continuous power from DC power source and enable camera use without recharging batteries. 
  
* <b>GPS</b>: <p align="justify"> It is one of the global navigation satellite systems (GNSS) that provides geolocation and time information to a GPS receiver anywhere on or near the Earth where there is an unobstructed line of sight to four or more GPS satellites.
  
  <p align="justify">The power control feature of GP-735 is very convenient to turn on/off power just via GPIO control pin. It???s especially useful to turn off power as the GPS function is not needed in the host applications.
  
  [GPS Datasheet](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/Documentation/datasheet-GP-735T.pdf)
  
* <b>Optocoupler</b>: <p align="justify"> An optocoupler is a semiconductor device that allows an electrical signal to be transmitted between two isolated circuits. It can control high currents with low currents without an electrical connection between two circuits and it provides electrical isolation to these two circuits. 
   
  <p align="justify"> The octocoupler serves the function of regulating the opening and closing of the shutter in this system. When a photograph is to be taken, the optocoupler supplies current to the shutter release, which subsequently activates the shutter button.
    
  [Optocoupler Datasheet](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/Documentation/datasheet-4N25.pdf)
  
  
* <b>Shutter Release</b>: <p align="justify"> Connects Remote Trigger to Camera. 

### 2.3 Functional Diagram
![Image](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/Documentation/FunctionalDiagram.png)

## 3.0 Practical Tutorial

[Step-by-Step Solder Tutorial](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/Tutorial/Step-by-Step.md)

[Enclusore Install Tutorial](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/Tutorial/CaseInstall.md)

[SD-Card Reader Test File](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/Tutorial/CardInfotest.ino)

[DC Coupler Test File](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/Tutorial/DCPartTest.ino)

[GPS Test File](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/Tutorial/GPSTester.ino)

[Shutter Release Test File](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/Tutorial/ShutterReleaseTester.ino)



## 4.0 Deployments
  

  
Daily TimeLapes Video:
<video src='https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/figure/DailyTimeLapse.mp4' width=180/>

  
Node-1             |  Node-2      
:-------------------------:|:-------------------------:
![](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/figure/2ndPic.jpeg)  |  ![](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/figure/3rdPic.jpeg)

Node-3      |  Node-4
:-------------------------:|:-------------------------:
![](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/figure/4thPic.jpeg)|  ![](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/figure/5thPic.jpeg)

Map of TPWSNSys Deployments
:-------------------------:
![Image](https://github.com/WhiteMuyi/Timelapse-Photogrammetry-Wireless-Sensing-Network/blob/main/figure/Earth.png)

