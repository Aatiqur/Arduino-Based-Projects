#include <Wire.h>
#include <ESP8266WiFi.h> 
#include <MPU6050.h>

#define period 10000

MPU6050 mpu;

int count=0;
char okFlag=0;


int SCL_PIN=D1;
int SDA_PIN=D2;

void setup() 
{
  WiFi.forceSleepBegin();
  Serial.begin(115200);
  Serial.println("Initialize MPU6050");
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
  count=0;

  mpu.calibrateGyro();
  mpu.setThreshold(3);
}

void loop()
{
 
      accelShow();

    
}

void accelShow()
{  
  Vector rawAccel = mpu.readRawAccel();
  Vector normAccel = mpu.readNormalizeAccel();
  
  Serial.print(" Xnorm = ");
  Serial.print(normAccel.XAxis);
  Serial.print(" Ynorm = ");
  Serial.print(normAccel.YAxis);
  Serial.print(" Znorm = ");
  Serial.println(normAccel.ZAxis);
  delay(200);
}
