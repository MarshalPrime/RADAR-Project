#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 9;
const int echoPin = 10;
const int buzzer=11;
const int ledPin =12;
long duration;
int distanceCm, distanceInch;
int safetyDistance;
void setup() {
Serial.begin(9600);
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Distance: "); // Prints string "Distance" on the LCD
lcd.print(distanceCm); // Prints the distance value from the sensor
lcd.print(" cm");
delay(10);
lcd.setCursor(0,1);
lcd.print("Distance: ");
lcd.print(distanceInch);
lcd.print(" inch");
delay(10);
safetyDistance = distanceCm;
if (safetyDistance <= 50)   // You can change safe distance from here changing value Ex. 20 , 40 , 60 , 80 , 100, all in cm
{
  tone(buzzer, 250);
  digitalWrite(ledPin, HIGH);
  Serial.write('0');
  delay(10);
}
else if(safetyDistance > 50)
{
  noTone(buzzer);
  digitalWrite(ledPin, LOW);
  Serial.write('1');
  delay(20);
  
}
  
  
}
