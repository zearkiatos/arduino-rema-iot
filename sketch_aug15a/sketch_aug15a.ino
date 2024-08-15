#include "DHT.h"
#define DHTTYPE DHT11  // DHT 11

#define dht_dpin 4
DHT dht(dht_dpin, DHTTYPE);

#define LED D1  // LED
int ValueRead = 2;
int myflag = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  dht.begin();
}

void loop() {
  if (Serial.available()) {
    ValueRead = Serial.parseInt();
  }
  if (((ValueRead == 1 && myflag == 0) || myflag == 1) & !(ValueRead == 2 && myflag == 1)) {
    digitalWrite(LED, HIGH);
    Serial.println("Turn On");
    myflag = 1;
  } else {
    digitalWrite(LED, LOW);
    Serial.println("Turn Off");
    myflag = 0;
  }
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Current humidity = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(t);
  Serial.println("C  ");
}