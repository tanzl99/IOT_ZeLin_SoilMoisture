#include <Arduino.h>
#include <WiFi.h>
#include <FirebaseESP32.h>
#include <LiquidCrystal.h>
/* 1. Define the WiFi credentials */
#define WIFI_SSID "I Need Friends"
#define WIFI_PASSWORD "BeepBoopBeep"
/* 2. Define the API Key */
#define API_KEY "AIzaSyDuV_XyvNUekT5innhAVW3c3vdPG6vozbk"
#define DATABASE_URL "https://esp32-t4-default-rtdb.asia-southeast1.firebasedatabase.app/" 
//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"
// Define Firebase Data object
/* 4. Define the user Email and password that alreadey registerd or added in your project */
#define USER_EMAIL "zelin_tan@mymail.sutd.edu.sg"
#define USER_PASSWORD "Sutd01041999!"
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
// Define button and LED pins
#define SOIL_MOISTURE_PIN A2
#define BUTTON_PIN 9

#define LCD_RS 10
#define LCD_E 1
#define LCD_D4 0
#define LCD_D5 4
#define LCD_D6 5
#define LCD_D7 6

// Initialize the alphanumeric LCD display
LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
int count = 0;
int moistureValue = 0;
int moistureRead = 0;

void setup()
{

  Serial.begin(115200);


  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
  /* Assign the api key (required) */
  config.api_key = API_KEY;
  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;
  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h
  // Comment or pass false value when WiFi reconnection will control by your code or third party library e.g. WiFiManager
  Firebase.reconnectNetwork(true);
  // Since v4.4.x, BearSSL engine was used, the SSL buffer need to be set.
  // Large data transmission may require larger RX buffer, otherwise connection issue or data read time out can be occurred.
  fbdo.setBSSLBufferSize(4096 /* Rx buffer size in bytes from 512 - 16384 */, 1024 /* Tx buffer size in bytes from 512 - 16384 */);
  Firebase.begin(&config, &auth);
  Firebase.setDoubleDigits(5);

  // Set pin modes
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Initialize LCD
  lcd.begin(16, 2);
  lcd.clear();

  Serial.println("Setup completed");

}

void loop() {
  // Check if the button is pressed
  if (digitalRead(BUTTON_PIN) == LOW) {
    // Read soil moisture
    moistureValue = analogRead(SOIL_MOISTURE_PIN);
    Serial.println(moistureValue);
    // Send soil moisture level to Firebase
    Firebase.setInt(fbdo, "/moistureValue", moistureValue);
  }

  // Read data from Firebase
  if (count == 15){
    if (Firebase.getInt(fbdo, "/moistureValue")) { // Check if data was read successfully
      moistureRead = fbdo.intData();
    }
    else {
      Serial.println("Error reading data from Firebase");
    }
    // Display moisture status on LCD
    Serial.println(moistureRead);
    if (moistureRead <= 3000) {
      Serial.print(" wet");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Please stop! I'm");
      lcd.setCursor(0, 1);
      lcd.print("already wet!!");
      delay(1000);
    } else {
      Serial.print(" dry");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("HELP!! Please");
      lcd.setCursor(0, 1);
      lcd.print("make me wet!! ;)");
      delay(1000);
    }
    count = 0;
  }
  count = count + 1;
  delay(100); // Check button state every second
}



