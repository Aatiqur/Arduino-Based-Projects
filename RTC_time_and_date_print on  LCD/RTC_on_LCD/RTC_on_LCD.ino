#include<Wire.h>
#include<DS1307.h>
#include <LiquidCrystal.h>
DS1307 rtcc;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(){
  lcd.begin(16,2);
  rtcc.set(00,02,11,23,03,20);//sec,min,hour,date,month,year
  rtcc.start();
}

void loop(){
  uint8_t sec,min,hour,day,month;
  uint16_t year;
  
  rtcc.get(&sec,&min,&hour,&day,&month,&year);

  lcd.setCursor(0,0);
  lcd.print("Time:");
  lcd.print(hour,DEC);
  lcd.print("-");
  lcd.print(min,DEC);
  lcd.print("-");
  lcd.print(sec,DEC);

  lcd.setCursor(0,1);
  lcd.print("Date:");
  lcd.print(day,DEC);
  lcd.print("/");
  lcd.print(month,DEC);
  lcd.print("/");
  lcd.print(year,DEC);

  delay(1000);

}
