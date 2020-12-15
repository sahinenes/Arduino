
int pirPin = 7;                   //Sensörü takacağımız pin
int ledPin=13;
int hareket;                      //Sensörden aldığımız veri
                      //Servo motor değişkeni


void setup() {
        
  pinMode(pirPin, INPUT);       //Sensör pinimizi giriş olarak ayarlyoruz.
   pinMode(ledPin, OUTPUT);   

}

void loop() {
  hareket = digitalRead(pirPin);  //Sensörden okuma yapıyoruz.
  
  if(hareket == HIGH){             //Hareketlilik var ise içerideki komutlar uygulanır.
  digitalWrite(ledPin,HIGH);
  }
  else{                           //Hareketlilik yok ise içerideki komutlar uygulanır.
   
    digitalWrite(ledPin,LOW);
  }
}
