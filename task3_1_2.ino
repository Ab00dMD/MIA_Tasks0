#include <Wire.h>

const int led = 9;

void setup() {
  // Set LED pin as output
  pinMode(led, OUTPUT);
  // Address of the receiver
  Wire.begin(9);   
  // Set receiveEvent as the callback function for I2C receive
  Wire.onReceive(receiveEvent); 
  // Initialize Serial Monitor
  Serial.begin(9600);        
}

void loop() {
  
}

void receiveEvent(int numOfBytes) {
  // Check  at least two bytes are received 00
  if (numOfBytes >= 2) {
    // Read the two bytes
    int b1_State = Wire.read();
    int b2_State = Wire.read();

    int ledIntensity = 0;
    String message = "No message";

    if (b1_State == 1 && b2_State == 0) {
      ledIntensity = 128; // 50% of maximum
      message = "Vector focused";
    } else if (b1_State == 0 && b2_State == 1) {
      ledIntensity = 192; // 75% of maximum
      message = "Vector distracted";
    } else if (b1_State == 1 && b2_State == 1) {
      ledIntensity = 255; // 100% of maximum
      message = "Glitch";
    }
    
    // Set LED brightness based on the determined intensity
    analogWrite(led, ledIntensity); 
    // Print the message to the Serial Monitor
    Serial.println(message);     
  }
}