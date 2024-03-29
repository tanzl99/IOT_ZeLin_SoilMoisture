
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

### Firebase
#### Getting into Firebase
1) Go to Firebase https://firebase.google.com/ and sign in using a Google Account.
2) Click "Get Started"
3) Click "Add project" to create a new project
4) Give it a name!

#### Authentication
1) Open up "Authentication" on the main console
2) Click "Get Started", this is essential to generate your unique API Key
3) Under "Sign-in providers", none (anonymous) is needed for testing purposes
4) Open up "Project settings" on the main console by clicking on the "gear" icon beside "Project Overview"
5) Under "General", copy and save the Web API Key

#### Realtime Database
1) Open up "Realtime Database" on the main console
2) Select your database location, preferably somewhere closest to you to minimise latency
3) Select "Start in test mode" since this is a test code so security is not a priority
4) Now that it is created, copy and save the database URL

#### Arduino IDE Library
1) You can use the starter code named "Starter.ino"
2) Install the Firebase ESP Client Library by mobizt: https://github.com/mobizt/Firebase-ESP32
3) Choose the Client most suitable for you (ESP8266 and/or ESP32)
4) Click "Add to Project"

### How my code works
#### Start
1) #include adds in required libraries, such as <WiFi.h> to connect to your network
2) #define assigns the variables such as "WIFI_SSID" and "DATABASE_URL" with the relevant information to be used later on
3) I also assigned shortened variable names such as fbdo for FirebaseData
4) Lastly, I initialised the Liquid Crystal Display (LCD Screen) and created variables for the Soil Moisture Sensor

#### Set up
1) Under "void setup()", the board begins the setup, connecting to your network
2) Then, the board attempts to connect and authenticate with Firebase
3) Lastly is to setup the "pin modes" for the button and initialise the LCD and clearing its screen

#### Actual Code
1) Under "void loop()" is where the main code is
2) Pressing the button retrieves the moisture value taken from the Soil Moisture Sensor "moistureRead)
3) That moisture value is then compared to the threshhold value of 3000 and a message is displayed
4) Since the LCD Screen is 16x2, only 16 characters can be displayed per line.
5) The Potentiometer is there to control the backlight of the LCD.
6) Lastly, since the "void loop()" is constantly looping, to prevent excessive clearing and displaying of lcd, the "count" function is added so each refresh has around a 1.5 second cooldown

## Future Upgrades
Since I did not have any budget, I only made do with the free parts lying around from previous projects for this projects.
Some potential upgrades in parts and more functions I thought would be nice to have are listed below.

### Part upgrades
#### ESP32 S3 or better upgrades
-Stronger and faster hardware
-More module compatability (some listed below)

#### OLED Display
-Although it is smaller than the LCD in terms of screen size, the ease of use is greatly appreciated. 

-A total of 12 pins plus soldering is required for the LCD Screen (1602A) compared to only 4 for the OLED Screen (SSD1306).

-More display options such as fontsize, fonts, shapes, images and even GIF and videos.

#### Capacitive Soil Moisture Sensor
-The cheaper resistive Soil Moisture Sensors passes current through the soil via the 2 probes, which causes electrolysis of the sensors, corroding and degrading it over time

-It is more reliable to measure as it measures ions dissolved in the moisture over the resistance of the soil. This is important as adding fertilisers decreases resistivity of the soil, "increasing" the soil moisture even though no water was added.

-More variables can be measured with the Capacitive Soil Moisture Sensor such as the aforementioned fertilisers

### Part Alternatives
#### Speaker Output
-Since I was using a ESP32 C3 devboard, I was unable to play much audio due to codec limitations.

-With upgrades to the devboard, audio can be played and used to replace or complement the screen

-One idea for the audio is with multiple plant and sensor setups. When the water moisture is acceptable, the speaker can play a specific note which harmonises with the rest. When the water moisture is unacceptable, the speaker can play another note which ruins the harmony



## GLHF
Don't blow up your house or something...
