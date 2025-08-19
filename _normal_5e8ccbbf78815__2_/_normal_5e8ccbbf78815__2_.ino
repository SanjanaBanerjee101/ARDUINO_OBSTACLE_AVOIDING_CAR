#define trigpin 12
#define echopin 13
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
long distance,duration;
digitalWrite(trigpin,LOW);
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);
duration = pulseIn(echopin,HIGH);
distance = (duration/2) / 29.1;

if(distance>=200 || distance<=0)
{
  Serial.println("Out of range");
}
else
{
  Serial.print("DISTANCE:");
  Serial.println(distance);
}
delay(500);
}
