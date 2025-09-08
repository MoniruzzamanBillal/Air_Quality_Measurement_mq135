#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// scl pin --> A5
// sda pin --> A4

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {


  lcd.setCursor(0, 0);
  lcd.print("Hello World!!!");

  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Testing l2c");
  lcd.setCursor(0, 1);
  lcd.print("Module display!!!");

  delay(2000);
  lcd.clear();
}
