# Automated Water Pump Version II

![Top View][4]

## Project Details

This project is an upgrade from the original water pump controller. The previous version was assembled over a 
proto-board rather than a PCB. The components were not SMD components and I used wires to connect them. The buck
converter was also not my own as it was a pre-built from Amazon.

Now, this version is built upon a PCB. The power jack allows both the water pump and the ESP32 to be powered. This 
project also takes advantage of my buck converter project by incorporating it into this schematic. This is the 
next level to creating a dedicated unit to control the water pump.

![Cinematic View][2]

## Parts

- ESP32-WROOM-2
- Stacking Headers
- 7V Power Supply
- Screw Terminal Block
- Barrel Power Adapter
- MOSFET Driver
- 1000uf 16V Capacitor
- Buck Converter (Visit Step Down Voltage Regulator project for details)

## Process

I first re-used the buck converter I created before and integrated it into my new project. Then, I worked on defining 
the header risers which the ESP32 will sit on and determined the pins I would use. I also defined the MOSFET and terminal
block connections

![Schematic View][3]

On the PCB side, I started with the power jack and led it to the buck converter. This time, the buck converter was flipped 
to accommodate the sides that the Vin and Out were on. This connected to the header risers which also has the MOSFET 
connected. This MOSFET is powered directly from the power jack where the gate is connected to the ESP32 and leads to the 
terminal block (also connected to GND). Thus, the circuit is complete.

![PCB View][1]

I made a few iterations of this PCB to make it smaller and thus, achieved and board size of 65x34mm or 2.5x1.3in. Last time,
I wanted to place the buck converter under the ESP32, but it was too tall to fit. However, this is no longer a problem now 
that I have a custom buck converter which has a much smaller profile.

## Conclusion

![Angle View][5]

This project has now allowed me to implement my buck converter in a real application. I am sure there could be optimizations, 
both in parts, and design. However, this is a good representation of where I am at the moment. Through this project, I have also 
gained more experience in SMD and THT soldering since I had 5 bare PCBs manufactured, but assembled them myself. I used PCBWay 
to manufacture the boards, and followed my BOM to order the components from DigiKey. Altogether, it cost me $55 for 5 boards.

The next step would be to create  my own fully custom PCB showcasing my buck converter, but also a fully custom ESP32. 
This way, instead of having a separate ESP32 unit to place on the headers, it would be integrated into the board. 
I will also be upgrading the terminal block to be a connection that has a proper male and female port.

![With ESP][6]

[//]: # (MEDIA)
[1]: Board%20Traces.png
[2]: Cinematic%20View.png
[3]: Schematic.png
[4]: top_view.jpg
[5]: angle_view.jpg
[6]: with_esp.jpg