
int mq135Pin = A0;


void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(mq135Pin);



  Serial.print("MQ-135 Value: ");
  Serial.print(sensorValue);

  Serial.print("  |  Air Quality: ");

  if (sensorValue < 300) {
    Serial.println("Good 😊");
  } else if (sensorValue < 600) {
    Serial.println("Moderate 😐");
  } else {
    Serial.println("Poor 😷");
  }


  delay(500);
}
