int line[4],threshold =970;
float duty =35;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readGroundSensors();// reading the values from the analog sensors(IR sensors)
  if(line[3]<threshold && line [0]<threshold )// checks 
  {
    
    Serial.println("j");
    leftMotorForward(duty);
    rightMotorForward(duty);
      
  }
  else if(line[3]<threshold && line[0]>=threshold)
  {
        Serial.println("k");
    rightMotorForward(duty);
    leftMotorBackward(duty-8);
  }
  else if(line[3]>=threshold && line[0]<threshold)
  {
        Serial.println("l");

    leftMotorForward(duty);
    rightMotorBackward(duty-8);
  }
else if(line[3]>=threshold && line[0]>=threshold)// when it detects two black spots it stops
{
      Serial.println("m");

   rightMotorStop();
   leftMotorStop();
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
