//# Jarak-dan-cahaya

#include <LiquidCrystal.h>

LiquidCrystal lcd(5,6,8,9,10,11);
const int trigPin = 3;
const int echoPin = 2;
long duration;
int distanceCm;
int hasilSensorLDR;
int progressBari = 0;
int i = 0;

byte progressBar[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
void setup() {
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
lcd.print("Hasil LDR :");
lcd.createChar(0, progressBar);
}

void loop() {
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;

//lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
//lcd.print("Distance: "); // Prints string "Distance" on the LCD
//lcd.print(distanceCm); // Prints the distance value from the sensor
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
 hasilSensorLDR = analogRead(A0);
  //lcd.setCursor(12,0);
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
  
  
