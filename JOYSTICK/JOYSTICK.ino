int xPin = A0;
int yPin = A1; 
int degerX;
int degerY;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(xPin, INPUT);
pinMode(yPin, INPUT);
}

void loop() {
 
degerX=analogRead(xPin);
degerY=analogRead(yPin);
Serial.print("X KONUMU: ");
Serial.println(degerX);
Serial.print("Y KONUMU: ");
Serial.println(degerY);
delay(100);
}
