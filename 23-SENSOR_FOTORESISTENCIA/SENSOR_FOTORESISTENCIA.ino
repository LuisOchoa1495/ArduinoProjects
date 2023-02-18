int analogPin=A0;
int bombilla=6;
int valorLDR;
void setup(){
  Serial.begin(9600);
  pinMode(bombilla,OUTPUT);
}
void loop(){
  valorLDR=analogRead(analogPin);
  Serial.println(valorLDR);
  if(valorLDR>400){
    digitalWrite(bombilla,HIGH);
  }
  else{
    digitalWrite(bombilla,LOW);
  }
  delay(100);
}
