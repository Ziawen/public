#include "I2Cdev.h" //I2C kütüphanesi
#include "MPU6050.h" //Mpu6050 kütüphanesi
#include "Wire.h"

MPU6050 accelgyro; // sensör tanımlama
int16_t ax, ay, az; //ivme tanımlama
int16_t gx, gy, gz; //gyro tanımlama
  
void setup() {
Wire.begin();
Serial.begin(38400);
accelgyro.initialize();
  
Serial.println(accelgyro.testConnection() ? "MPU6050 bağlandı" : "MPU6050 bağlanılamadı");
}
  
void loop() {
  
accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

//ekran çıktıları
Serial.print("a/g:\t");
Serial.print(ax); Serial.print("\t");
Serial.print(ay); Serial.print("\t");
Serial.print(az); Serial.print("\t");
Serial.print(gx); Serial.print("\t");
Serial.print(gy); Serial.print("\t");
Serial.println(gz);
}
