#include <Wire.h>

const int button1 = 2;
const int button2 = 3;

void setup() {
  //Initialize I2C communication
  Wire.begin(); 
  // Set button1 & button2 as input with internal pull-up resistor enabled
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

void loop() {
  // Read the state of the buttons
  int b1_State = digitalRead(button1);  
  int b2_State = digitalRead(button2);  

  // Address of the receiver
  Wire.beginTransmission(9); 
  // Send the states of the buttons 
  Wire.write(b1_State);
  Wire.write(b2_State);
  Wire.endTransmission();

  delay(100); 
}