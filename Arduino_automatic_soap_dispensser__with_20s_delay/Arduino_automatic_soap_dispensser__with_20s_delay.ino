#include <Servo.h>

Servo myservo; 
int trigPin = 8;    
int echoPin = 9;    
long duration,distance;
int pos(0);
int fire(180);
int led = 11;
 
void setup() {
  myservo.attach(10);
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.write(pos);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}
 
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;   
 
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
  delay(250);

  if(distance <= 20){
     myservo.write(fire);
     Serial.println("triggered");
     delay(500);
     myservo.write(pos);
  }
  else{
     myservo.write(pos);
      
  }
   if(distance <= 19){
    
     digitalWrite(led,HIGH);
     delay(20000);
     
  }
  else{
      digitalWrite(led,LOW);
}
}
