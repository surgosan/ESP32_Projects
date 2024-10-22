# Step Down Voltage Regulator

![Cover][1]

In order to progress on projects for the future, I need a way to convert
higher voltages to lower voltages in DC-DC. I decided to create my own
step-down voltage regulator or buck converter to accomplish this.

![Schematic][5]

I explored various modules to help me progress in this project. I ultimately
went with the TI TPS564257DRLR buck converter to reduce an input voltage of
7-12V down to 3.5V. I went over the datasheet to get vital information such as
max/recommended inputs and outputs as well as applications to help design
my schematic.

![Back][2]
I used Altium Designer to design my schematic as well as create the PCB. Once
I had fixed electrical and design rule issues, I contacted PCBWay to have it
manufactured. I communicated with them to ensure they had all the information
they needed such as the BOM (Bill of Materials) and ultimately got approved.

![Left][3]
I ordered 5 different modules. I had PCBWay also assemble 2 of them, but the rest of
them, I used to practice SMD soldering. I then used my DC power supply to test 
various DC inputs between 7-12V and used a multimeter to check the output.

It was a success. It output 3.5V regardless of what the input voltage was which
was perfect to use in future projects where I may want to power a 12V actuator 
and a 3-5V microcontroller. 

![PCB][6]

I will be using this module to integrate into other projects. This way, I now
have a reliable solution to meet my MCU power needs. The first project I will
apply this to is my automated water fountain project to upgrade from a
proto-board with wires, to a dedicated PCB.

![Back][4]

[//]: # (MEDIA)
[1]: front.png
[2]: back.png
[3]: left%20side.png
[4]: right%20side.png
[5]: schematic.png
[6]: pcb%20design.png