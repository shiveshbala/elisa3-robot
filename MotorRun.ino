float duty =50;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
leftMotorForward(duty);
rightMotorBackward(duty);
delay(3000);
leftMotorBackward(duty);
rightMotorForward(duty);
delay(3000);


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
