// C++ code
//
int sensorValue=0;
int ledDimming=0;
int pwmPin=9;

void setup()
{
  pinMode(A0,INPUT);
  Serial.begin(9600);
  pinMode(pwmPin,OUTPUT);
}

void loop()
{
 //read the value from the sensor
  sensorValue = analogRead(A0);
 //printf the sensor reading so you know its range
 Serial.print("PhotoResistor Read = ");
 Serial.println(sensorValue);
 //map the sensor reading to a range for the LED
 ledDimming=map(sensorValue, 700, 925, 0, 255);
  if( ledDimming<0) ledDimming=0;
  Serial.print(",      ledDimming  value = ");
  Serial.println(ledDimming);
  //Serial.print("Dimming led value =");
  //Serial.println(ledDimming);
  analogWrite(pwmPin,ledDimming);
  delay(100);//Wait for 100 millisecond(s)
}
