#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int tempPin = A0;

void setup() {
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hi! I'm ArduTemp");
  Serial.begin(9600);
  delay(1500);
}

void loop() {
  int sensorVal = analogRead(tempPin);
 Serial.print("sensor Value: ");
  Serial.print(sensorVal);
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("sV:");
  lcd.setCursor(3,0);
  lcd.print(sensorVal);
  lcd.setCursor(7,0);
  lcd.print("| V:");
  lcd.setCursor(11,0);
  lcd.print(voltage);
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.setCursor(5,1);
  lcd.print(temperature);
  lcd.setCursor(11,1);
  lcd.print("deg C");
  delay(500);
}
