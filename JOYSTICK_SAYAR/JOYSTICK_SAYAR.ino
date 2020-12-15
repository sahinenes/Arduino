
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//I2C pins declaration
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


int xPin = A0;
int degerX;
int pirPin = 2;   
int sayi;
int ledPin=13;
int hareket;
unsigned long eskiZaman=0;
unsigned long yeniZaman;
void setup() {
  pinMode(pirPin, INPUT); 
  pinMode(xPin, INPUT);
  pinMode(ledPin, OUTPUT); 
   sayi=0;
 
 lcd.begin(16,2);//Defining 16 columns and 2 rows of lcd display
 lcd.backlight();//To Power ON the back light
    //lcd.backlight();// To Power OFF the back light

}

void loop() {

  yeniZaman = millis();
  // put your main code here, to run repeatedly:
  degerX=analogRead(xPin);


 if(yeniZaman-eskiZaman > 1000 && degerX>=930){
  sayi++; 
  lcd.setCursor(0,0);
lcd.print("                ");
     /* Eski zaman değeri yeni zaman değeri ile güncelleniyor */
     eskiZaman = yeniZaman;
  }
   if(yeniZaman-eskiZaman > 1000 && degerX<=10){
  sayi--; 
  lcd.setCursor(0,0);
lcd.print("                ");
     /* Eski zaman değeri yeni zaman değeri ile güncelleniyor */
     eskiZaman = yeniZaman;
  }
lcd.setCursor(0,0);
//Defining positon to write from first row,first column .
lcd.print(sayi);



  hareket = digitalRead(pirPin);  //Sensörden okuma yapıyoruz.
  
  if(hareket == HIGH){             //Hareketlilik var ise içerideki komutlar uygulanır.
  digitalWrite(ledPin,HIGH);
  lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
lcd.print("HAREKET VAR");
  }
  else{                           //Hareketlilik yok ise içerideki komutlar uygulanır.
   
    digitalWrite(ledPin,LOW);
    lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
lcd.print("HAREKET YOK");
  }



}
