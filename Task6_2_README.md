## Encoder Cutoff Frequency Calculation
In our system, we have the following parameters:
- Pulses per rotation: 540
- Wheel radius: 0.2 meters
- Maximum speed: 0.5 m/s

To determine the proper cutoff frequency (fc) for our Low-Pass Filter (LPF), we follow these steps:

1. **Calculate Rotations per Second (RPS)**:
   - We calculate the rotational speed of the wheel in revolutions per second (RPS) using the formula:
     ```
     RPS = Maximum Speed / (2 * π * Wheel Radius)
     ```
   - Substituting the values:
     ```
     RPS = 0.5 / (2 * 3.14 * 0.2) ≈ 0.398 RPS
     ```

2. **Calculate Pulses per Second (PPS)**:
   - PPS represents the rate at which the encoder generates pulses per second. We calculate it by multiplying the pulses per rotation by the RPS:
     ```
     PPS = Pulses per Rotation * RPS
     ```
   - Substituting the values:
     ```
     PPS = 540 * 0.398 ≈ 214.968 PPS
     ```

3. **Determine Cutoff Frequency (fc)**:
   - We consider the PPS value as our cutoff frequency for the LPF:
     ```
     Cutoff Frequency (fc) ≈ 214.968 Hz
     ```

This calculated cutoff frequency is approximately 214.968 Hz.

### Documentation
``` cpp
/*
   Rotary Encoder Pulse Counting

   This code interfaces with a rotary encoder and counts pulses from the A and B signals.
   It uses interrupts to detect changes in the encoder signals and increments or decrements
   a counter based on the rotation direction.

   Encoder Pins:
   - A phase of the encoder is connected to digital pin 2 (PinA).
   - B phase of the encoder is connected to digital pin 3 (PinB).

   The count of pulses is printed to the serial monitor.

   Hardware Setup:
   - Ensure that the encoder is properly connected to the specified pins.
   - Connect GND and VCC of the encoder to ground and 5V, respectively.
*/

// Define constants for the encoder pins
#define PinA 2  // Connect A phase of encoder to digital pin 2
#define PinB 3  // Connect B phase of encoder to digital pin 3

// Counter for encoder pulses
long unsigned int count = 0;

void setup() {
  // Initialize the serial communication at 9600 baud rate
  Serial.begin(9600);

  // Set the pins as inputs with internal pull-up resistors
  pinMode(PinA, INPUT_PULLUP);
  pinMode(PinB, INPUT_PULLUP);

  // Attach interrupts to handle changes on both A and B phases
  attachInterrupt(digitalPinToInterrupt(PinA), handleEncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PinB), handleEncoderB, CHANGE);
}

void loop() {
  Serial.println(count);
  // Add a delay to control the rate of printing
  delay(50);
}

// Interrupt service routine for handling changes on A phase
void handleEncoderA() {
  if (digitalRead(PinA) != digitalRead(PinB))
    count++;  // Increment count for clockwise rotation
  else
    count--;  // Decrement count for counterclockwise rotation
}

// Interrupt service routine for handling changes on B phase
void handleEncoderB() {
  if (digitalRead(PinA) == digitalRead(PinB))
    count++;  // Increment count for clockwise rotation
  else
    count--;  // Decrement count for counterclockwise rotation
}
```

