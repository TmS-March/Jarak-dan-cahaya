#include <LiquidCrystal.h>

LiquidCrystal lcd(5,6,8,9,10,11);
const int trigPin = 3;
const int echoPin = 2;
long duration;
int distanceCm;
int hasilSensorLDR;



void setup() {
lcd.begin(16,2);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(A1, INPUT);
}

void loop() {
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;

//lcd.setCursor(0,0); 
//lcd.print("Distance: "); 
//lcd.print(distanceCm); 
//lcd.print("  cm");
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

{
  
lcd.setCursor(0,1);
 lcd.print("Hasil LDR :");
 hasilSensorLDR = analogRead(A1);
 // lcd.setCursor(12,0);
  //lcd.print(cahaya);
  lcd.print(hasilSensorLDR);
  delay(1000);
  lcd.clear();
  delay(1000);
  //progressBari=map(hasilSensorLDR, 0, 1000, 0, 17);
  //for (i=0; i<progressBari; i++)
  //{
   //lcd.setCursor(i, 1);
    //lcd.write(byte(0));
  //}
}
}
  
  
