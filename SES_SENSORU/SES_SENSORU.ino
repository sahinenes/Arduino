int soundSensor=A0;
int LED=8;
boolean LEDStatus=false;

void setup() {
 pinMode(soundSensor,INPUT);
 pinMode(LED,OUTPUT);
 Serial.begin(9600);

}

void loop() {

  int SensorData=analogRead(soundSensor); 
  Serial.println(SensorData);
  delay(500);
  if(SensorData>523){

    if(LEDStatus==false){
        LEDStatus=true;
        digitalWrite(LED,HIGH);
    }
    else{
        LEDStatus=false;
        digitalWrite(LED,LOW);
    }
  }
 } 
