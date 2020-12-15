int latchPin = 5;
int clockPin = 6;
int dataPin = 4;
byte leds = 0;
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}
 
void loop() 
{
  leds = 0;
  registeraYaz();
  delay(500);
  for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    registeraYaz();
    delay(500);
  }
  for (int i = 8; i >= 0; i--)
{
    bitClear(leds, i);
    registeraYaz();
    delay(500);
  }
}
void registeraYaz()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
