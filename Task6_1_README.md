### Q1:what type of filter could used and what is the recommended cutoff frequency depending on the sensor datasheet?
 ==> We could use low-pass-filter(LPF) with cutoff frequency = 0.707 * 256 = 181 
 // NOTE: Gyro Bandwidth of DLPF_CFG @ 0 is 256
### Documentation
```cpp
#include <Wire.h>

// Define I2C address and register addresses for the MPU6050
#define MPU_ADDRESS 0x68
#define GYRO_CONFIG 0x1B
#define PWR_MGMT_1 0x6B
#define GYRO_ZOUT_H 0x47

// Variables for storing gyro data and Yaw angle
float gyroRateZ = 0.0;
float yawAngle = 0.0;

// Time step for integration (10ms)
float dTime = 0.01;

void setup() {
  // Initialize I2C communication
  Wire.begin();
  Serial.begin(9600);
  
  // Wake up the MPU6050 sensor and configure gyro scale (±250 DPS)
  Wire.beginTransmission(MPU_ADDRESS);
  // Select the power management register
  Wire.write(PWR_MGMT_1);
  // Set to 0 to wake up the sensor
  Wire.write(0);          
  Wire.endTransmission();
  
  Wire.beginTransmission(MPU_ADDRESS);
  // Select the gyro configuration register
  Wire.write(GYRO_CONFIG);
  // Set gyro scale to ±250 DPS
  Wire.write(0x00);        
  Wire.endTransmission();
}

void loop() {
  // Request and read gyroscope data
  Wire.beginTransmission(MPU_ADDRESS);
  // Select the starting register for gyro data
  Wire.write(GYRO_ZOUT_H); 
  Wire.endTransmission();
  // Request 2 bytes of gyro data
  Wire.requestFrom(MPU_ADDRESS, 2);
  while(wire.available()<2);
  // Combine the high and low bytes
  int gyroZ = Wire.read() << 8 | Wire.read(); 
  
  // Convert raw gyro data to angular velocity (DPS)
  // Sensitivity: 131 LSB/deg/s
  RateZ = gyroZ / 131.0;
  
  // Integrate gyro data to calculate Yaw angle
  yawAngle += RateZ * dTime;

  // Print Yaw Angle to the serial monitor
  Serial.print("Yaw Angle = ");
  Serial.println(yawAngle);

  // Delay to maintain a consistent loop execution rate (10ms)
  delay(10);
}
