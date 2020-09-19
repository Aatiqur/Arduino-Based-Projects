#include <IRremote.h>
 
int IR_Recv = 11; 
int yellow = 13;
int val;
IRrecv irrecv(IR_Recv);
decode_results results;

void setup(){
  Serial.begin(9600);  
  irrecv.enableIRIn(); 
  pinMode(yellow, OUTPUT); 
}

void loop(){
  val=digitalRead(13);
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(results.value);

    if( results.value==3997951 && val==0){
      digitalWrite(yellow,HIGH);
    }
     if( results.value==3997951 && val==1){
      digitalWrite(yellow,LOW);
    }
    

     irrecv.resume();
  }
  delay(10);
}
