#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define LDR_PIN A1
#define ACS_PIN A0

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  int lightValue = analogRead(LDR_PIN);
  int currentValue = analogRead(ACS_PIN);

  Serial.print("TEMP:");
  Serial.print(temp);

  Serial.print(",HUM:");
  Serial.print(hum);

  Serial.print(",LIGHT:");
  Serial.print(lightValue);

  Serial.print(",CURRENT:");
  Serial.println(currentValue);

  delay(2000);
}
