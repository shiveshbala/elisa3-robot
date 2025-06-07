int light[8];
unsigned char i;
void setup() {
  Serial.begin(300);
  DDRA |= 0B00000001;
}

void loop() {
  for(i=0;i<8;i++)
  {
  proxLEDon(i);
  delay(10);
  Serial.print("Proximity Sensor value of ");
  Serial.print(i);
  Serial.print(" is ");
  Serial.println(analogRead(0));
  proxLEDoff(i);
  }
}

void proxLEDon(unsigned char proxIndex)
{
  PORTA |= (1<<proxIndex);
}
void proxLEDoff(unsigned char proxIndex)
{
  PORTA &= ~(1<<proxIndex);
}
int readProximitySensors(unsigned char proxIndex)
{
  return analogRead(proxIndex); 
}
