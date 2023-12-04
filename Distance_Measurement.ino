#include <LiquidCrystal.h>
// Define the pins for the ultrasonic sensor
const int trigPin = 9;  // Trigger pin
const int echoPin = 10; // Echo pin
// const int buzzer = 13;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // pinMode(buzzer,OUTPUT);
  lcd.begin(16,2);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  long duration = pulseIn(echoPin, HIGH);

  // (speed of sound in air is approximately 343 meters per second)
  float distance_cm = duration * 0.034 / 2;

  // if(distance_cm<=50){
  //   digitalWrite(buzzer,HIGH);
  //   delay(100);
  //   digitalWrite(buzzer,LOW);
  //   delay(50);
  //   digitalWrite(buzzer,HIGH);
  //   delay(100);
  //   digitalWrite(buzzer,LOW);
  // }
  Serial.print("Distance: ");
  Serial.print(int(distance_cm));
  Serial.println(" cm");
  int d= int(distance_cm);
  lcd.setCursor(0,0);
  lcd.print("Distance is :");
  lcd.setCursor(0,1);
  lcd.print(d);
  lcd.print(" cm");
  delay(1000);
  lcd.clear();
  // delay(1000); // Add a delay to avoid rapid measurements
}