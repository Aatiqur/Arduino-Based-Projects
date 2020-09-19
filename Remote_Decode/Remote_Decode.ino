#include <IRremote.h>

int IRpin = 12;
IRrecv irrecv(IRpin);
decode_results results;
int led =8;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(led,OUTPUT);
}  
void loop() 

{   
  if (irrecv.decode(&results)) 
    {
     Serial.println(results.value); // Print the Serial 'results.value'
      delay(10);
      if(results.value==4053541){
      digitalWrite(led,HIGH);
      }
      

     irrecv.resume();   // Receive the next value
    }
}    
