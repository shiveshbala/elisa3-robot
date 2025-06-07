void setup() {
  Serial.begin(300);

}

void loop() {
  Serial.print("Proximity Sensor 0: ");
  Serial.println(analogRead(0));  
}
