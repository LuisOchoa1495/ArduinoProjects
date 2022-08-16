int led1=7;
int led2=8;
int led3=9;
int valor;
void setup() {
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
}
void loop() {
valor=analogRead(A1);//VALORES DE 0 -1024

if(valor<=300){
digitalWrite(led1,HIGH);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
}

if(valor>300 & valor<=700){
digitalWrite(led1,HIGH);
digitalWrite(led2,HIGH);
digitalWrite(led3,LOW);
}

if(valor>700){
digitalWrite(led1,HIGH);
digitalWrite(led2,HIGH);
digitalWrite(led3,HIGH);
}
}
