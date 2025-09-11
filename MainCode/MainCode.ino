#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>


#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


int mq135Pin = A0;



LiquidCrystal_I2C lcd(0x27, 16, 2);

// scl pin --> A5
// sda pin --> A4



void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {


  int mq135Value = analogRead(mq135Pin);
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();



  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("⚠️ Failed to read from DHT11 sensor!");
    delay(2000);
    return;
  }



  String airStatus;
  if (mq135Value < 200) {
    airStatus = "GOOD Air";

  } else if (mq135Value >= 200 && mq135Value < 400) {
    airStatus = "MODERATE Air";

  } else {
    airStatus = "POOR Air!";
  }


  // ----- Show on Serial -----
  Serial.println("------ Environment Status ------");
  Serial.print("Air Quality (MQ135): ");
  Serial.print(mq135Value);
  Serial.print(" → ");
  Serial.println(airStatus);

  Serial.print("Temperature (DHT11): ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity (DHT11): ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.println("--------------------------------------");
  Serial.println();



  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("AirQ Val=");
  lcd.print(mq135Value);
  lcd.setCursor(0, 1);
  lcd.print(airStatus);
  delay(3000);



  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T=");
  lcd.print(temperature);
  lcd.print("C H=");
  lcd.print(humidity);
  lcd.print("%");

  lcd.setCursor(0, 1);
  if (temperature > 30) {
    lcd.print("Status: HOT");
  } else if (temperature < 15) {
    lcd.print("Status: COLD");
  } else if (humidity > 70) {
    lcd.print("Status: Humid!");
  } else if (humidity < 30) {
    lcd.print("Dry Air");
  } else {
    lcd.print("Status: OK");
  }
  delay(3000);




  lcd.clear();
}
