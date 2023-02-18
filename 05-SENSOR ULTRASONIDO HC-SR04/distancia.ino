int led=6;
int trig=8;
int echo=9;
int duracion;
int distancia;

void setup() {
pinMode(led,OUTPUT);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
}
void loop() {
digitalWrite(trig,HIGH);
delay(1);
digitalWrite(trig,LOW);
duracion=pulseIn(echo,HIGH);
distancia=duracion/58.2;
delay(200);
if(distancia<=20 && distancia>0){
  digitalWrite(led,HIGH);
  delay(distancia*15);
  digitalWrite(led,LOW);
}
}
