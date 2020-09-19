#include <IRremote.h>
IRsend irsend;
int button1 = 8;
int button2 = 9;
int button3 = 10;
int button4 = 11;
int button5 = 12;

void setup() {
  Serial.begin(9600);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  pinMode(button4,INPUT);
  pinMode(button5,INPUT);
}

void loop() {
  if(digitalRead(button1)==HIGH){
     irsend.sendNEC(3997951,32); 
     delay(50);   
     Serial.println("1"); 
  }
    if(digitalRead(button2)==HIGH){
     irsend.sendNEC(4002541,32); 
     delay(50);
     Serial.println("2");
  }
    if(digitalRead(button3)==HIGH){
     irsend.sendNEC(4035181,32);
     delay(50);
     Serial.println("3");
  }
    if(digitalRead(button4)==HIGH){
     irsend.sendNEC(4018861,32); 
     delay(50);
     Serial.println("4");
  }
    if(digitalRead(button5)==HIGH){
     irsend.sendNEC(4051501,32);
     delay(50);
     Serial.println("5");
  }
 
 delay(50);
  
}
