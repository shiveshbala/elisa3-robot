float duty=35;
int x,y;
void setup() {
  // put your setup code here, to run once:
  DDRA |= 0B00000001;
}

/*void loop() {
  // put your main code here, to run repeatedly:
y= readProximitySensors(0);
if(y<890)
{
  leftTurn();
  delay(500);
}
else
{
  rightMotorForward(30);
  leftMotorForward(30);
}

}

void leftMotorForward(float duty)
{
  analogWrite(7,0);
  analogWrite(6,duty);
}
void leftMotorBackward(float duty)
{
  analogWrite(6,0);
  analogWrite(7,duty);
}
void leftMotorStop()
{
  analogWrite(7,0);
  analogWrite(6,0);
}
void rightMotorForward(float duty)
{
  analogWrite(2,0);
  analogWrite(5,duty);
}
void rightMotorBackward(float duty)
{
  analogWrite(5,0);
  analogWrite(2,duty);
}
void rightMotorStop()
{
  analogWrite(5,0);
  analogWrite(2,0);
}


int readProximitySensors(unsigned char proxIndex)
{
  return analogRead(proxIndex); 
}*/
int line[4],threshold =970;
void loop() {
  proxLEDon(0);
  delay(10);
  y= analogRead(0);
  proxLEDoff(0);
if(y<=860)
{
  leftTurn();
  delay(100);
}
else
{
  rightMotorForward(30);
  leftMotorForward(30);
}
  // put your main code here, to run repeatedly:
  readGroundSensors();// reading the values from the analog sensors(IR sensors)
  if(line[2]<threshold && line [1]<threshold )// checks 
  {
    
    Serial.println("j");
    leftMotorForward(duty);
    rightMotorForward(duty);
      
  }
  else if(line[2]<threshold && line[1]>=threshold)
  {
        Serial.println("k");
        leftMotorForward(duty);
    rightMotorBackward(duty-8);
    
    
  }
  else if(line[2]>=threshold && line[1]<threshold)
  {
        Serial.println("l");

    rightMotorForward(duty);
    leftMotorBackward(duty-10);
  }
else if(line[2]>=threshold && line[1]>=threshold)// when it detects two black spots it stops
{
      Serial.println("m");

   rightMotorForward(duty);
   leftMotorBackward(duty);
   delay(500);
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
      line[i]=analogRead(8+i);
      groundLEDoff(i);
    }
  }
  void leftMotorForward(float duty)
  {
    analogWrite(7,0);
    analogWrite(6,duty);
  }
  void leftMotorBackward(float duty)
  {
    analogWrite(6,0);
    analogWrite(7,duty);
  }
  void leftMotorStop()
  {
    analogWrite(7,0);
    analogWrite(6,0);
  }
  void rightMotorForward(float duty)
  {
    analogWrite(2,0);
    analogWrite(5,duty);
  }
  void rightMotorBackward(float duty)
  {
    analogWrite(5,0);
    analogWrite(2,duty);
  }
  void rightMotorStop()
  {
    analogWrite(5,0);
    analogWrite(2,0);
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
void leftTurn()
{
  rightMotorForward(30);
  leftMotorForward(10);
}
void rightTurn()
{
  rightMotorForward(10);
  leftMotorForward(30);
}
