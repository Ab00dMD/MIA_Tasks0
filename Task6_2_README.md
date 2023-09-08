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
