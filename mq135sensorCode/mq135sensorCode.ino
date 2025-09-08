#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int mq135Pin = A0;
int mqdigital = 3;

LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
   pinMode(mqdigital, INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
 
  int sensorValue = analogRead(mq135Pin);
   int digitalValue  = digitalRead(mqdigital);



  Serial.print("MQ-135 Value: ");
  Serial.print(sensorValue);
   Serial.println(" ");

     Serial.print("digitalValue: ");
  Serial.print(digitalValue);
Serial.println(" ");


  lcd.setCursor(0, 0);
  lcd.print("sensor=" + sensorValue );
  lcd.setCursor(0, 1);
  lcd.print("digital=" + digitalValue );

  // if (sensorValue < 300) {
  //   Serial.println("Good 😊");
  // } else if (sensorValue < 600) {
  //   Serial.println("Moderate 😐");
  // } else {
  //   Serial.println("Poor 😷");
  // }


  delay(500);
    lcd.clear();
}
