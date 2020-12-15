

#include <Keypad.h>


//lcd kütühaneleri
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//I2C pins declaration
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

///


//RTC kütüphaneleri

// CONNECTIONS:
// DS1302 CLK/SCLK --> 5
// DS1302 DAT/IO --> 4
// DS1302 RST/CE --> 2
// DS1302 VCC --> 3.3v - 5v
// DS1302 GND --> GND

#include <ThreeWire.h>  
#include <RtcDS1302.h>

ThreeWire myWire(4,5,2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);
//////

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
bool alarm_kur;
bool onayla;
bool sifirla;
String durum;
void setup(){
   Serial.begin(57600);
  
  alarm_kur=false;
  onayla=false;
  sifirla=false;
  

  ///keypad
 
  customKeypad.setDebounceTime(10);
  customKeypad.setHoldTime(0);
  customKeypad.addEventListener(keypadEvent);
  hour1=String("0");
  hour2=String("0");
  minute1=String("0");
  minute2=String("0");
  durum=String("Alarm Yok");
  say=-1;
  


  /////

  ///RTC

    Serial.print("Derlenen: ");
    Serial.print(__DATE__);
    Serial.println(__TIME__);

    Rtc.Begin();

    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    
    Serial.println(printDateTime(compiled));

    if (!Rtc.IsDateTimeValid()) 
    {
        // Common Causes:
        //    1) first time you ran and the device wasn't running yet
        //    2) the battery on the device is low or even missing

        Serial.println("RTC lost confidence in the DateTime!");
        Rtc.SetDateTime(compiled);
    }

    if (Rtc.GetIsWriteProtected())
    {
        Serial.println("RTC was write protected, enabling writing now");
        Rtc.SetIsWriteProtected(false);
    }

    if (!Rtc.GetIsRunning())
    {
        Serial.println("RTC was not actively running, starting now");
        Rtc.SetIsRunning(true);
    }

    RtcDateTime now = Rtc.GetDateTime();
    if (now < compiled) 
    {
        Serial.println("RTC is older than compile time!  (Updating DateTime)");
        Rtc.SetDateTime(compiled);
    }
    else if (now > compiled) 
    {
        Serial.println("RTC is newer than compile time. (this is expected)");
    }
    else if (now == compiled) 
    {
        Serial.println("RTC is the same as compile time! (not expected but all is fine)");
    }


  ///


///LCD

 lcd.begin(16,2);//Defining 16 columns and 2 rows of lcd display
 lcd.backlight();//To Power ON the back light
 //lcd.backlight();// To Power OFF the back light


///

 
}


void loop(){

  
RtcDateTime now = Rtc.GetDateTime();




    if (!now.IsValid())
    {
        // Common Causes:
        //    1) the battery on the device is low or even missing and the power line was disconnected
        Serial.println("RTC lost confidence in the DateTime!");
    }

lcd.setCursor(0,0); //Defining positon to write from first row,first column .
lcd.print( printDateTime(now));




lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
lcd.print(hour1+hour2+":"+minute1+minute2+" "+durum);




char key = customKeypad.getKey();

if(onayla==true)
{
  
  if(now.Hour()==(hour1+hour2).toInt()&&now.Minute()==(minute1+minute2).toInt())
{
  
  lcd.clear();
  lcd.setCursor(0,0);  //Defining positon to write from second row,first column .
  lcd.print("UYANN!    UYANN!");
  lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
  lcd.print("UYANN!    UYANN!");
  delay(2000);
}
  
}



/*
    if (key == 'A') {
            alarm_kur=true; 
            Serial.println("kur");       
        }



if(alarm_kur==true)
{
  
     
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
*/
}


#define countof(a) (sizeof(a) / sizeof(a[0]))

String printDateTime(const RtcDateTime& dt)
{
    char datestring[20];

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Month(),
            dt.Day(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );

        return datestring;
   // Serial.print(datestring);
}


void keypadEvent(KeypadEvent key){
    switch (customKeypad.getState()){
    case PRESSED:
        if (key == 'A') {
            alarm_kur=true; 
            durum="kuruluyor";
            hour1=String("0");
            hour2=String("0");
            minute1=String("0");
            minute2=String("0");
            say=-1;
            lcd.clear();
            Serial.println("kur");       
        }

          if (key == 'B') {
            onayla=true; 
            durum="kuruldu";
            lcd.clear();
            Serial.println("onayla");       
        }

        if (key == 'C') 
        {
         hour1=String("0");
         hour2=String("0");
         minute1=String("0");
         minute2=String("0");
         say=-1;
         lcd.clear();
        alarm_kur=false;
        onayla=false;
        durum="Alarm Yok"; 
          
        }
        
        

      if(alarm_kur==true)
{
  
     
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
        
        break;

    case RELEASED:
      
        break;

    case HOLD:
      
        break;
    }
}
