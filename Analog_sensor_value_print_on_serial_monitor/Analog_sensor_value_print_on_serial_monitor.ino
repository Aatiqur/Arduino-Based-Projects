int sensor =A3;
float value;

void setup(){
  Serial.begin(9600);
  pinMode(sensor,INPUT);
}
void loop(){
  value=analogRead(sensor);
  Serial.println(value);
  delay(500);
}
