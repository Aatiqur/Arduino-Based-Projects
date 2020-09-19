void setup(){
  pinMode (13,OUTPUT);
 Serial.begin(9600);
}
void loop(){
  if(Serial.available()>0){
    int r =Serial.parseInt();
    
    Serial.println(r);
  
  }
  }
