//variables
int interruptor =11;
int valor=0;
int entrada1=7;
int entrada2=6;

void setup()
{
pinMode(interruptor, INPUT);
pinMode(entrada1, OUTPUT);
pinMode(entrada2, OUTPUT);
digitalWrite(10, HIGH);
}

void loop()
{
valor= digitalRead(interruptor);
  if (valor==1) {
    digitalWrite(entrada1, LOW);
    digitalWrite(entrada2, HIGH);
  }
  else{
    digitalWrite(entrada1, LOW);
    digitalWrite(entrada2, LOW);        
  }
}
