constintpingPin = 10; // Trigger Pin of Ultrasonic Sensor

constintechoPin = 11; // Echo Pin of Ultrasonic Sensor

constint motor1F = 2;

constint motor1B = 3;

constint motor2F = 4;

constint motor2B = 5;

constint mode = 6;

boolean flag;

void setup()
{

pinMode(pingPin,OUTPUT);

pinMode(echoPin, INPUT);

pinMode(motor1F,OUTPUT);

pinMode(motor1B,OUTPUT);

pinMode(motor2F,OUTPUT);

pinMode(motor2B,OUTPUT);

pinMode(mode,INPUT);

flag = true;

}

void loop()

{

digitalWrite(motor1F,HIGH);

digitalWrite(motor1B,LOW);

digitalWrite(motor2F,HIGH);

digitalWrite(motor2B,LOW);




long duration, inches, cm;

digitalWrite(pingPin, LOW);

delayMicroseconds(2);

digitalWrite(pingPin, HIGH);


delayMicroseconds(10); digitalWrite(pingPin, LOW); duration = pulseIn(echoPin, HIGH); inches = microsecondsToInches(duration); cm = microsecondsToCentimeters(duration);

if(inches<15 &&digitalRead(mode) == HIGH)

{

if(flag == true)

{

digitalWrite(motor1F,LOW);

digitalWrite(motor1B,LOW);

digitalWrite(motor2F,LOW);

digitalWrite(motor2B,LOW);

delay(200);

digitalWrite(motor1F,HIGH);

digitalWrite(motor1B,LOW);

digitalWrite(motor2F,LOW);

digitalWrite(motor2B,LOW);

delay(2400);


digitalWrite(motor1F,HIGH);

digitalWrite(motor1B,LOW);

digitalWrite(motor2F,HIGH);

digitalWrite(motor2B,LOW);

delay(1000);

flag = false;}




else if(flag == false)

{

digitalWrite(motor1F,LOW);

digitalWrite(motor1B,LOW);

digitalWrite(motor2F,LOW);

digitalWrite(motor2B,LOW);

delay(200);

digitalWrite(motor1F,LOW);

digitalWrite(motor1B,LOW);

digitalWrite(motor2F,HIGH);

digitalWrite(motor2B,LOW);

delay(2400);

digitalWrite(motor1F,HIGH);

digitalWrite(motor1B,LOW);

digitalWrite(motor2F,HIGH);

digitalWrite(motor2B,LOW);

delay(1000);

flag = true;}

}

else if(inches<15 &&digitalRead(mode) == LOW)

{

if(flag == true)

{

digitalWrite(motor1F,LOW);

digitalWrite(motor1B,LOW);

digitalWrite(motor2F,LOW);
digitalWrite(motor2B,LOW);
delay(200);
digitalWrite(motor1F,LOW);
digitalWrite(motor1B,LOW);
digitalWrite(motor2F,HIGH);
digitalWrite(motor2B,LOW);
delay(2400);
digitalWrite(motor1F,HIGH);
digitalWrite(motor1B,LOW); 
digitalWrite(motor2F,HIGH);

digitalWrite(motor2B,LOW);

delay(1000);

flag = false;}

else if(flag == false)

{

digitalWrite(motor1F,LOW);

digitalWrite(motor1B,LOW);

digitalWrite(motor2F,LOW);

digitalWrite(motor2B,LOW);
delay(200);
digitalWrite(motor1F,HIGH);
digitalWrite(motor1B,LOW);
digitalWrite(motor2F,LOW);
digitalWrite(motor2B,LOW);
delay(2400);
digitalWrite(motor1F,HIGH);
digitalWrite(motor1B,LOW);
digitalWrite(motor2F,HIGH);
digitalWrite(motor2B,LOW);
delay(1000);
flag = true;
}
}
}
longmicrosecondsToInches(long microseconds)
{
return microseconds / 74 / 2;
}
longmicrosecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}
