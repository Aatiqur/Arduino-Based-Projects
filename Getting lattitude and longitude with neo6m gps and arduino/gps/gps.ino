#include <TinyGPS++.h>

TinyGPSPlus gps;



String link;

void setup(){
  Serial.begin(9600);
  Serial.println("ok");
}

void loop(){
   Serial.println("ok1");

while (Serial.available() > 0){
   if( gps.encode(Serial.read())){
    Serial.println("ok2");
     
      Serial.print("Latitude= "); 
      float lattitude=gps.location.lat();
      Serial.print(lattitude,   6);
      
      Serial.print(" Longitude= "); 
      float longitude=gps.location.lng();
      Serial.println(longitude, 6);
      
      Serial.print("Number of Satelites connected: "); 
      Serial.println(gps.satellites.value());


      link="http://maps.google.com/maps?q=" + String(lattitude,8)+","+String(longitude,8);
      Serial.println(link);

    
    }
  }
}
