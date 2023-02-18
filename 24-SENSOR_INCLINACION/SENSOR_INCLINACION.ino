int tilt=3;
int led=12;
int buzzer=11;
void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(tilt, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  if(digitalRead(tilt))//el sensor de inclinacion toma valores 1 y 0 para indicar se se inclino el sensor
  {
  tone(buzzer,700,500);
    digitalWrite(led,HIGH);
    delay(500);
  }else
  {
    noTone(buzzer);
    digitalWrite(led,LOW);
    delay(500);
  }
  delay(10); 
}
