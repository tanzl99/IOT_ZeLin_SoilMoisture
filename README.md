
# Tan Ze Lin's ESP32 PDS IOT Project

This project is for PDS, where I have an input and output through firebase using an ESP32 C3 Mini 1 developer board.



## Things used in this project
### Hardware components
x1 ESP32-C3-Mini-1 Developer Board (must be able to connect to WiFi, I got mine from ESPRESSIF)
x1 Potentiometer (b10k)
x1 LCD Display (1602A ver5.5)
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
![soil moisture pinout](https://github.com/tanzl99/IOT_ZeLin_SoilMoisture/assets/71513813/5cb6189c-63a2-4f67-9411-0f90860c905c)
[![IMAGE ALT TEXT HERE]([https://github.com/tanzl99/IOT_ZeLin_SoilMoisture/assets/71513813/8f962381-21f8-4974-9070-d987d70a20da](https://github.com/tanzl99/IOT_ZeLin_SoilMoisture/assets/71513813/8f962381-21f8-4974-9070-d987d70a20da))](https://www.youtube.com/watch?v=DUF6QH1VmHw)

