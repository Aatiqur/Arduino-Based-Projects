#include <LiquidCrystal.h>
  LiquidCrystal lcd(12,11,7,6,5,4);

  int potPin = A0;
  int soil=0;
 
void setup(){
   lcd.begin(16,2);
   lcd.print("MOISTURE : ");
   Serial.begin(9600);
}
 
void loop(){  
   int soil = analogRead(potPin);
   soil = constrain(soil, 485, 1023);
   soil = map(soil, 485, 1023, 100, 0);
   lcd.setCursor(10,0);
   lcd.print(soil);
   lcd.print("%");
   Serial.print("%");
    Serial.println(soil);
 lcd.setCursor(0,1);
   if(soil >= 60){
    lcd.print("need no water");
    
   }else{
     lcd.print("need water");
   }
   delay(75);
   lcd.print(" ");
   delay(1);
 }
