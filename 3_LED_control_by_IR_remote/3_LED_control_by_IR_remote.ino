#include <IRremote.h>
 
int IR_Recv = 11;   //IR Receiver Pin 3
int bluePin = 10;
int greenPin = 9;
int yellowPin = 8;
 
IRrecv irrecv(IR_Recv);
decode_results results;
 
void setup(){
  Serial.begin(9600);  //starts serial communication
  irrecv.enableIRIn(); // Starts the receiver
  pinMode(bluePin, OUTPUT);      // sets the digital pin as output
  pinMode(greenPin, OUTPUT);      // sets the digital pin as output
  pinMode(yellowPin, OUTPUT);      // sets the digital pin as output 

}
 
void loop(){
  //decodes the infrared input
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(results.value);
    //switch case to use the selected remote control button
    switch (results.value){
      case 4038751: 
        digitalWrite(bluePin, HIGH);
        break;   
      case 4022431: 
        digitalWrite(bluePin, LOW);   
        break;
       case 4055071: 
        digitalWrite(greenPin, HIGH);
        break;           
       case 4002031:
        digitalWrite(greenPin, LOW);
        break;       
       case 4034671: 
        digitalWrite(yellowPin, HIGH);
        break;       
       case 4018351: 
        digitalWrite(yellowPin, LOW);
        break;
    }
    irrecv.resume(); // Receives the next value from the button you press
  }
  delay(10);
}
