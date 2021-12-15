void setup() {
  pinMode(2, OUTPUT);   // GPIO 2 yaitu pin D4 di nodeMCU adalah LED dekat antenna pada NodeMCU
}

void loop() {
  digitalWrite(2, LOW); // LED menyala bila LOW
  delay(1000);

  digitalWrite(2, HIGH);
  delay(1000);
}