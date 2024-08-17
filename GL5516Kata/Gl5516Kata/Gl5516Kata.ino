int ldrPin = A0;   // Analog pin connected to the LDR
int ldrValue = 0;  // Variable to store the LDR value

#define LED D0

void setup() {
  Serial.begin(9600);  // Start the serial communication
  delay(10);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  ldrValue = analogRead(ldrPin);  // Read the value from the LDR
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);  // Print the value to the Serial Monitor

  if (ldrValue > 600) {
      digitalWrite(LED, LOW);
      Serial.print("Light turned off ");
  }
  
  if (ldrValue <= 600) {
    digitalWrite(LED, HIGH);
    Serial.print("Light turned on");
  }

  delay(500);  // Wait for 500 milliseconds before reading again
}