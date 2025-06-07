int line[4];
void setup() {
  // put your setup code here, to run once:
Serial.begin(300);
}

void loop() {
  // put your main code here, to run repeatedly:
readGroundSensors();
for(int i=0;i<4;i++)
{
  Serial.print("Sensor ");
  Serial.print(i);
  Serial.print(" ");
  Serial.println(line[i]);
}
}
void groundLEDon(unsigned char LineIndex)
{
  PORTJ |= (1<<LineIndex);
}
void groundLEDoff(unsigned char LineIndex)
{
  PORTJ &= ~(1<<LineIndex);
}
void readGroundSensors()
{
  for( int i=0; i<4;i++)
  {
    groundLEDon(i);
    delay(10);
    line[i]=analogRead(8+i);
    groundLEDoff(i);
  }
}
