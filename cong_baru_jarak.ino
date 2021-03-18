#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x16, 16, 2);
#define trigPin D3
#define echoPin D4
long duration;
int distanceCm;
int hasilSensorLDR;

void setup() {
lcd.begin(16,2);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(A0, INPUT);
Serial.begin(9600);
}

void loop() {
lcd.setCursor(0,0);
lcd.print("Bilik Pintar");
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
Serial.println(analogRead(A0));
Serial.println(distanceCm);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
if ( 25 < distanceCm)
{
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Jarak Baca: ");
     lcd.print(distanceCm);
     lcd.print ("cm");
     delay(1000);
     lcd.clear();  
     delay(1000);
 }
   else 
  {
    lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Jarak Baca: ");
     lcd.print(distanceCm);
     lcd.print ("cm");
     delay(1000);
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Terlalu Dekat");
     lcd.setCursor(0,1);
     lcd.print("Mundur Woi");
     delay(1000); 
     lcd.clear();
     delay (1000);
   }

hasilSensorLDR = analogRead(A0);
if (48<hasilSensorLDR)
  {
    lcd.setCursor(0,1);
    lcd.print("Hasil LDR: ");
    lcd.print(hasilSensorLDR);
    delay(1000);
    lcd.clear();  
    delay(1000);
  }
  else
  {
    lcd.setCursor(0,1);
    lcd.print("Hasil LDR: ");
    lcd.print(hasilSensorLDR);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Kurang Cahaya");
    delay(1000); 
    lcd.clear();
    delay (1000);
  }
}
