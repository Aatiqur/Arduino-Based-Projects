#include<SoftwareSerial.h>;
SoftwareSerial BT(9,10);//TX,RX
String readdata;
int led1=13;
int led2=11;
int led3=12;
int led4=8;
int led5=6;
int led6=7;


void setup(){
      BT.begin(9600);
  Serial.begin(9600);
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);
  
  
}
void loop(){
  while(BT.available()){
    delay(10);
    char c=BT.read();
    readdata +=c;
  }
  
    if(readdata.length()>0)
    {
      Serial.println(readdata);
 //////////////////////////////////////////////////    
  if(readdata=="1"){
  digitalWrite(led1,HIGH);
 
  }
    if(readdata=="2"){
  digitalWrite(led1,LOW);
 
  }
    if(readdata=="3"){
  digitalWrite(led2,HIGH);
  }
    if(readdata=="4"){
  digitalWrite(led2,LOW);
 
  }
    if(readdata=="5"){
  digitalWrite(led3,HIGH);
 
  }
    if(readdata=="6"){
  digitalWrite(led3,LOW);
 
  }
    if(readdata=="7"){
  digitalWrite(led4,HIGH);
 
  }
    if(readdata=="8"){
  digitalWrite(led4,LOW);
 
  }
    if(readdata=="9"){
  digitalWrite(led5,HIGH);
 
  }
    if(readdata=="10"){
  digitalWrite(led5,LOW);
 
  }
    if(readdata=="11"){
  digitalWrite(led6,HIGH);
 
  }
    if(readdata=="12"){
  digitalWrite(led6,LOW);
 
  }
  
/////////////////////////////////////////////////// 
  readdata="";
}
}
