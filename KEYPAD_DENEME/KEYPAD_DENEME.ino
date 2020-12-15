#include <Keypad.h>
 
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
 
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {10, 11, 12, 13}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad


Keypad kpd = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

unsigned long timer_ms = 0;

void setup(){
  Serial.begin(9600);
  
  // Try playing with different debounceTime settings to see how it affects
  // the number of times per second your loop will run. The library prevents
  // setting it to anything below 1 millisecond.
  kpd.setDebounceTime(10);  // setDebounceTime(mS)
}

void loop(){
  char key = kpd.getKey();
  
  // Report the number of times through the loop in 1 second. This will give
  // you a relative idea of just how much the debounceTime has changed the
  // speed of your code. If you set a high debounceTime your loopCount will
  // look good but your keypresses will start to feel sluggish.
  if ((millis() - timer_ms) > 1000) {

    timer_ms = millis();
  }
 
  if(key)
    Serial.println(key);
}
