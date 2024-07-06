# Automated Water Pump

![Main Image][6]


I began working on this project whenever the water pump for my cat's water fountain began to fail.
At the moment, it is simply using a 12V water pump to pump water. However, it does not stop pumping
water which is a waste of energy.

Thus, I began working on this project to save energy by turning off the water pump at night when everyone
is asleep. I also want to be able to control it from my phone, so I can turn it off or on if needed.

## Parts

- ESP32-WROOM-2
- Stacking Headers
- Proto-Board
- 3d Printed Enclosure
- 12V Power Supply
- Buck Converter (LM2596)
- Solid Core 20 Gauge Wire
- Screw Terminal Blocks
- Barrel Power Adapter
- MOSFET Driver
- 10 kOhm Resistor
- 1000uf 16V Capacitor

<div style="display: flex;">
    <img src="https://raw.githubusercontent.com/surgosan/ESP32_Projects/main/ESP32-WROOM-32/Projects/Automated_Water_Pump/IMG_3683.jpg" style="width: 50%;" alt="Image 1">
    <img src="https://raw.githubusercontent.com/surgosan/ESP32_Projects/main/ESP32-WROOM-32/Projects/Automated_Water_Pump/IMG_3682.jpg" style="width: 50%;" alt="Image 2">
</div>

## Process

I started by creating a prototype of the device. I used a full sized breadboard to house everything,
but I will be reducing it to half a breadboard. This allowed me to more easily test the circuits to 
ensure that the project works as intended.

Once I found a method that would reliably work, I started working on a more permanent solution. I used a proto-board
as the base on my project. I focused on fitting everything on a half-sized board to conserve space. While I did want to 
make this a permanent solution, I wanted the be able to change out the ESP32 if I needed, so I soldered stacking headers.
This way I can easily remove it at any time. 

<div style="display: flex;">
    <img src="https://raw.githubusercontent.com/surgosan/ESP32_Projects/main/ESP32-WROOM-32/Projects/Automated_Water_Pump/IMG_3690.jpg" style="width: 50%;" alt="Image 1">
    <img src="https://raw.githubusercontent.com/surgosan/ESP32_Projects/main/ESP32-WROOM-32/Projects/Automated_Water_Pump/IMG_3688.jpg" style="width: 50%;" alt="Image 2">
</div>

My PSU outputs 12V, so I used a buck converter to reduce it to 5V for the ESP32. I also added a capacitor since the pump uses
a little more than 12V when starting, and it was causing my ESP32 to reset. I used a MOSFET driver as the gate for turning
on and off the pump since it would be able to withstand a higher voltage compared to a transistor.

Once I was able to securely power on my water pump, I added the functionality to automatically turn on at 6AM and turn off
at 11PM. This way, I can reduce the amount of current the device uses over time. I also ended up reducing the voltage to 
6V since the water pump was much too strong for to be used as a water fountain for a cat.

![Working Prototype][4]

[//]: # (MEDIA)
[1]: IMG_3692.jpg
[2]: IMG_3682.jpg
[3]: IMG_3683.jpg
[4]: IMG_3688.jpg
[5]: IMG_3690.jpg
[6]: IMG_3692.jpg