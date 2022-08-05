
/*
 * Demo code for TMP36 temperature sensor.
 */
 
int sensorPin = A5;
int ledPin = 13;
int output = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float degC = getDegC();

  if (output == LOW && degC >= 27) {
    output == HIGH;
  }
  if (output == HIGH && degC < 25) {
    output == LOW;
  }

  digitalWrite(ledPin, output);
}

float getDegC() {
  int sensorValue = analogRead(sensorPin);
  float mV = sensorValue / 1023.0 * 5.0 * 1000;
  Serial.print(mV);
  Serial.print("mV ");

  float degC = (mV - 500) / 10;
  Serial.print(degC);
  Serial.println("degC");

  return degC;
}
