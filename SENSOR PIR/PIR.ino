int pir=7;
int led=8;
int estado;

void setup()
{
pinMode(led,OUTPUT);
pinMode(pir,INPUT);
} 

void loop(){
estado=digitalRead(pir);
  if(estado==HIGH){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
delay(10);
}
