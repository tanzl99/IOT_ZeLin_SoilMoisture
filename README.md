
# Tan Ze Lin's ESP32 PDS IOT Project

This project is for PDS, where I have an input and output through firebase using an ESP32 C3 Mini 1 developer board.
[![IMAGE ALT TEXT HERE](https://github.com/tanzl99/IOT_ZeLin_SoilMoisture/assets/71513813/8f962381-21f8-4974-9070-d987d70a20da)](https://www.youtube.com/watch?v=DUF6QH1VmHw)
(Click it, its a video from Youtube!)



## Things used in this project
### Hardware components
x1 ESP32-C3-Mini-1 Developer Board (must be able to connect to WiFi, I got mine from ESPRESSIF)
x1 Potentiometer (b10k)
x1 LCD (1602A ver5.5)
x1 Button
x1 Resistive Soil Moisture Sensor
Jumper wires

### Software
Arduino IDE (with Firebase Library)

## Story
Would it be nice to keep track of your plants, to be able to communicate more with them?

This soil moisture project serves as a base design to achieve that goal, with room for future growth, development scalability.

## How it works
1) Upon powering up, the board connects to the pre-selected WiFi and establishes connection with the pre-selected Firebase.

2) Upon button press, the sensor reading is sent to the Firebase.

3) The board then retrieves that data and compares it with a preset moisture threshhold, displaying one message if its below the threshhold, and another if its above the threshhold.

## You can do it too!!
### Install the relevant libraries
Firebase ESP32 by mobizt: https://github.com/mobizt/Firebase-ESP32

Liquid Crystal Display (LCD) by Adafruit https://github.com/adafruit/Adafruit_LiquidCrystal
 
### Pinouts
![soil moisture pinout](https://github.com/tanzl99/IOT_ZeLin_SoilMoisture/assets/71513813/5cb6189c-63a2-4f67-9411-0f90860c905c)]
Soil Moisture Sensor (Resistive) Pinout Diagram
- Connect the Power Supply pin (labelled "VCC") to a +3.3V header on the devboard (labelled "3V3").
- Connect Ground pin (labelled "GND") to a Ground header on the devboard.
- Connect Analog Output pin (labelled AO) to any GPIO header (I used GPIO Pin 2).
  *Note: Digital Outpin pin works as well, but I used Analog so its Pin "A2" in my code.
  
![Screen pinout](https://github.com/tanzl99/IOT_ZeLin_SoilMoisture/assets/71513813/86ece50a-8317-4557-9dfd-56f01c151b4d)
LCD Screen Pinout Diagram
![Screenshot 2024-03-15 183553](https://github.com/tanzl99/IOT_ZeLin_SoilMoisture/assets/71513813/7dfd22b4-76ba-488b-b97a-8b14a5bf500a)
LCD Pinout
- Connect Potentiometer and Pins 2 and 15 of the LCD IN PARALLEL (usually labelled "VDD" and "A" respectively) to a 5V header on the devboard (labelled "5V").
- Connect Potentiometer and Pins 1, 5 and 16 of the LCD IN PARALLEL (usually labelled "VSS", "RW" and "K" respectively) to a Ground header on the devboad (labelled "GND").
- Connect Potentiometer to Pin 3 of the LCD (usually labelled VO).
- Connect Pins 4, 6, 11, 12, 13 and 14 of the LCD (usually labelled "RS", "E", "D4", "D5", "D6" and "D7" respectively) to the devboard, each to a respective GPIO Header. (I used GPIO Pin 10, 1, 0, 4, 5 and 6 respectively)

Lastly, I connected a button to my devboard (I used GPIO Pin 9 and Ground).
