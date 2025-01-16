#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define trigPin A0 
#define echoPin A1 

long distanceInch;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


  lcd.begin(16, 2, LCD_5x8DOTS); 
  lcd.backlight(); 
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Simple Circuits");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Distance:"); 
  lcd.setCursor(0, 1);
  lcd.print("Distance:");
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration / 2) / 29.1; // cm
  distanceInch = duration * 0.0133 / 2; // inches

  lcd.setCursor(9, 0);
  lcd.print("                ");
  lcd.setCursor(9, 0);
  lcd.print(distance);
  lcd.print(" cm");

  // Display distance in inches
  lcd.setCursor(9, 1);
  lcd.print("                ");
  lcd.setCursor(9, 1);
  lcd.print(distanceInch);
  lcd.print(" inch");

  delay(200);
}
