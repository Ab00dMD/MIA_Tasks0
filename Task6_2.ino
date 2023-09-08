#define PinA 2  // Connect A phase of encoder to digital pin 2
#define PinB 3  // Connect B phase of encoder to digital pin 3

long unsigned int count = 0;  // Counter for encoder pulses

void setup() {
  Serial.begin(9600);
  pinMode(PinA, INPUT_PULLUP);  // Enable internal pull-up resistor for A phase
  pinMode(PinB, INPUT_PULLUP);  // Enable internal pull-up resistor for B phase
  
  // Attach an interrupt to handle changes on both A and B phases
  attachInterrupt(digitalPinToInterrupt(PinA), handleEncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PinB), handleEncoderB, CHANGE);
}

void loop() {
  Serial.println(count);
  delay(50);
}

void handleEncoderA() {
  if (digitalRead(PinA) != digitalRead(PinB))
    count++;
  else
    count--;
}

void handleEncoderB() {
  if (digitalRead(PinA) == digitalRead(PinB))
    count++;
  else
    count--;
}
