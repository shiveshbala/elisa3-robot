float duty = 25;// speed of the motor
int x, y, line[4], threshold = 970;//declaration of integer variables
void setup() 
{
  Serial.begin(9600);//helpful while testing out which part of the if is executing
  DDRC &= B11110000;//Set outputs by clearing bits
  DDRL |= B11110111;//Sets input by clearing bits
  DDRG |= B00001000;//Sets input by clearing bits
  DDRA |= 0B00000001;//Sets input by clearing bits
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if (SelectorPosition() == 1)// when the position of the switch is set to 1
  {
    Linefollow();//runs the first task function
  }
  else if (SelectorPosition() == 2)// when the position of the switch is set to 2
  {
    StayBox();//runs the second task function
  }
  else if (SelectorPosition() == 3)// when the position of the switch is set to 3
  {
    Linefollow2();//runs the third task function
  }
}
unsigned char SelectorPosition()
{
  return PINC & 0X0F;//Returns the value of the white switch
}
void Linefollow() //task 1 function
{
  readGroundSensors();// reading the values from the analog sensors(ground sensors)
  if (line[3] < threshold && line [0] < threshold )  // When [3] and [0] detects white 
  {

    Serial.println("j");
    leftMotorForward(duty);
    rightMotorForward(duty);//robot moves forward

  }
  else if (line[3] < threshold && line[0] >= threshold)// When [3] detects white and [0] detects black
  {
    Serial.println("k");
    rightMotorForward(duty);
    leftMotorBackward(duty - 8);//robot moves to the left
  }
  else if (line[3] >= threshold && line[0] < threshold)// When [3] detects black and [0] detects white
  {
    Serial.println("l");

    leftMotorForward(duty);
    rightMotorBackward(duty - 8);//robot moves to the right
  }
  else if (line[3] >= threshold && line[0] >= threshold) // When both [3] and [0] detects black
  {
    Serial.println("m");

    rightMotorStop();
    leftMotorStop();//the motors stop rotating
  }
}
void StayBox()//Task 2 function
{
  readGroundSensors();// reading the values from the analog sensors(Ground sensors)
  if (line[2] < threshold && line [1] < threshold ) // When [2] and [1] detects white 
  {

    Serial.println("j");
    leftMotorForward(duty);
    rightMotorForward(duty);//robot moves forward

  }
  else if (line[2] < threshold && line[1] >= threshold)// When [2] detects white and [1] detects black 
  {
    Serial.println("k");
    leftMotorForward(duty);
    rightMotorBackward(duty - 8);//robot moves to the right


  }
  else if (line[2] >= threshold && line[1] < threshold)// When [2] detects black and [1] detects white 
  {
    Serial.println("l");

    rightMotorForward(duty);
    leftMotorBackward(duty - 8);//robot moves to the left
  }
  else if (line[2] >= threshold && line[1] >= threshold) // When [2] and [1] detect black 
  {
    Serial.println("m");

    rightMotorForward(duty);
    leftMotorBackward(duty);
    delay(500);//delay added for the whole robot to turn around about 180 degrees
  }
}
void Linefollow2()// task 3 function
{
  readGroundSensors();// reading the values from the analog sensors(Ground sensors)
  if (line[2] < threshold && line [1] < threshold ) // When [2]  and [1] detect white
  {

    Serial.println("j");
    leftMotorForward(duty);
    rightMotorForward(duty);//robot moves forward

  }
  else if (line[2] < threshold && line[1] >= threshold)//When[2] detects white and [1] detects black
  {
    Serial.println("k");
    rightMotorForward(duty);
    leftMotorBackward(duty - 8);//robot moves to the left
  }
  else if (line[2] >= threshold && line[1] < threshold)//When[2] detects black and [1] detects white
  {
    Serial.println("l");

    leftMotorForward(duty);
    rightMotorBackward(duty - 8);//robot moves to the right
  }
  else if (line[2] >= threshold && line[1] >= threshold) // when it detects two black spots it stops
  {
    Serial.println("m");
    rightMotorStop();
    leftMotorStop();// The robot stops
  }
}
void groundLEDon(unsigned char LineIndex)//turn on the Ground sensor LEDS
{
  PORTJ |= (1 << LineIndex);
}
void groundLEDoff(unsigned char LineIndex)//turn off the Ground sensor LEDS after used
{
  PORTJ &= ~(1 << LineIndex);
}
void readGroundSensors()//reading the values of the Ground sensors down the robot to detect black lines
{
  for ( int i = 0; i < 4; i++)
  {
    groundLEDon(i);
    line[i] = analogRead(8 + i);
    groundLEDoff(i);
  }
}
void leftMotorForward(float duty)//Left motor Forward
{
  analogWrite(7, 0);
  analogWrite(6, duty);
}
void leftMotorBackward(float duty)//Left motor Backward
{
  analogWrite(6, 0);
  analogWrite(7, duty);
}
void leftMotorStop()//Left motor Stop
{
  analogWrite(7, 0);
  analogWrite(6, 0);
}
void rightMotorForward(float duty)//Right motor Forward
{
  analogWrite(2, 0);
  analogWrite(5, duty);
}
void rightMotorBackward(float duty)//Right motor Backward
{
  analogWrite(5, 0);
  analogWrite(2, duty);
}
void rightMotorStop()//Right motor Stops
{
  analogWrite(5, 0);
  analogWrite(2, 0);
}
void proxLEDon(unsigned char proxIndex)//turn on the Proximity LED
{
  PORTA |= (1<<proxIndex);//Set input by clearing bits
}
void proxLEDoff(unsigned char proxIndex)//Turn off the proximity LED
{
  PORTA &= ~(1<<proxIndex);//Set outputs by clearing bits
}
int readProximitySensors(unsigned char proxIndex)//Reads the value from the proximity sensor
{
  return analogRead(proxIndex); 
}
