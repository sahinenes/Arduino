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


Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


String hour1;
String hour2;
String minute1;
String minute2;
int say;

void setup(){

  customKeypad.setDebounceTime(250);
  hour1="";
  hour2="";
  minute1="";
  minute2="";
  Serial.begin(9600);
  say=0;
}


void loop(){
    char key = customKeypad.getKey();
     
         if(key)
        {
           say++; 
        }
        if(say==1)
        {
           hour1=key;
           Serial.print(hour1);
         }
         if(say==2 )
         {

            hour2=key;
            Serial.print(hour2);
          }
          if(say==3 )
          { 
             minute1=key;
             Serial.print(minute1);
          }
          if(say==4 )
          { 
             minute2=key;
             Serial.print(minute2);
             //  Serial.print(String(hour1)+String(hour2)+":"+String(minute1)+(minute2);
          }

}
