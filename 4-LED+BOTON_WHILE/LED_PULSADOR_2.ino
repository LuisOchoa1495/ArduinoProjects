int led=8;
int pulsador=7;
int estado=LOW;
void setup() {
pinMode(led,OUTPUT);
pinMode(pulsador,INPUT);
digitalWrite(led,1);
}
void loop() {
while(digitalRead(pulsador)==LOW);
estado=digitalRead(led);
digitalWrite(led, !estado);
while(digitalRead(pulsador)==HIGH);
}
