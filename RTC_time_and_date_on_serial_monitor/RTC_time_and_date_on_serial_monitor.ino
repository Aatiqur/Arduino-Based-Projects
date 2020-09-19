#include<Wire.h>
#include<DS1307.h>

DS1307 rtc;

void setup(){
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Init RTC..........");
  rtc.set(30,39,9,23,03,20);//sec,min,hour,date,month,year
  rtc.start();
  
}

void loop(){
  uint8_t sec,min,hour,day,month;
  uint16_t year;
  
  rtc.get(&sec,&min,&hour,&day,&month,&year);
  
  Serial.print("\n\nTime:");
  Serial.print(hour,DEC);
  Serial.print("-");
  Serial.print(min,DEC);
  Serial.print("-");
  Serial.print(sec,DEC);

  
  Serial.print("\nDate:");
  Serial.print(day,DEC);
  Serial.print("/");
  Serial.print(month,DEC);
  Serial.print("/");
  Serial.print(year,DEC);
  delay(1000);
}
