#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 =7 ;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float LM35_val;
int LM35_Pin = 0;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,4);
}
void loop()
{
  LM35_val = analogRead(LM35_Pin);
  
  float mv = ( LM35_val / 1024.0) * 5000;
  float cel = mv / 10;
  
  Serial.print("TEMPRATURE in Celcius = ");
 
  Serial.print(cel);
 
  Serial.print("*C");
  Serial.println();
  lcd.setCursor(0,0);
  lcd.print("Temp=");
  lcd.print(cel);
  lcd.print("*C");
  delay(1000);
 
}
