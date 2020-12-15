///lcd
//a5 scl
//a4 sda
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//I2C pins declaration
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 


/////hcrs04
#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
   ///lcd ayarları
   lcd.begin(16,2);//Defining 16 columns and 2 rows of lcd display
   lcd.backlight();//To Power ON the back light

   /////
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
 
 // Send ping, get distance in cm and print result (0 = outside set distance range)
lcd.setCursor(0,0); //Defining positon to write from first row,first column .
lcd.print( sonar.ping_cm());
lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
lcd.print("ENES SAHIN SAAT");

 delay(50);
 lcd.setCursor(0,0); 
lcd.print("                ");
}
