#include <Wire.h>

#define MPU_ADDRESS 0x68
#define GYRO_CONFIG 0x1B
#define PWR_MGMT_1 0x6B
#define GYRO_ZOUT_H 0x47

float gyroRateZ = 0.0;
float yawAngle = 0.0;
float dTime = 0.01; // 10ms

void setup() {
  Wire.begin(); 
  Serial.begin(9600);
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(PWR_MGMT_1);
  Wire.write(0);    
  Wire.endTransmission();
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(GYRO_CONFIG); 
  Wire.write(0x00);        
  Wire.endTransmission();
}

void loop() {
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(GYRO_ZOUT_H);
  Wire.endTransmission();
  Wire.requestFrom(MPU_ADDRESS, 2);
  while(wire.available()<2);
  int gyroZ = Wire.read() << 8 | Wire.read();
  RateZ = gyroZ / 131.0; 
  yawAngle += RateZ * dTime;

  Serial.print("Yaw Angle = ");
  Serial.println(yawAngle);

  delay(10);
}
