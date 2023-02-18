#include <IRremote.h>    //call the IR liberary
int RECV_PIN = 2;       //set pin 11 as input of IR
IRrecv irrecv(RECV_PIN); //define the name of ir led is irrecv
decode_results results;  //to reseive the value and decode it to number
int led1=13;
int led2=12;
int led3=11;
/*
-----------------------------------
  buttons:
  0 : 0xFD30CF
  1 : 0xFD08F7
  2 : 0xFD8877
  3 : 0xFD48B7
  4 : 0xFD28D7
  5 : 0xFDA857
  6 : 0xFD6897
  7 : 0xFD18E7
  8 : 0xFD9867
  9 : 0xFD58A7
--------------------------------------
*/
void setup(){
  Serial.begin(9600);   //define the serial monitor
  irrecv.enableIRIn();  //Enable IR
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(led3,OUTPUT);
}
void loop() {
  if (irrecv.decode(&results))// recibe valor hexagesimal
  {
    Serial.println(results.value, HEX); 
    irrecv.resume();// Después de recibir, debe llamarse para restablecer el receptor y prepararlo para recibir otro código. 
  }
  delay(100);
  switch (results.value) {
    case 0xFD30CF:
      Serial.println("0");
      encender_led(0);
      break;
    case 0xFD08F7:
      Serial.println("1");
      encender_led(1);
      break;
    case 0xFD8877:
      Serial.println("2");
      encender_led(2);
      break;
    case 0xFD48B7:
      Serial.println("3");
      encender_led(3);
      break;
  }
}
void led(int a, int b, int c){
    digitalWrite(led1,a);
    digitalWrite(led2,b);
    digitalWrite(led3,c);  
}

void encender_led(int n){
  switch(n){
    case 0: led(0,0,0);// enciende 0 led 
    break;
    case 1: led(1,0,0);// enciende 1 led 
    break;
    case 2: led(1,1,0);// enciende 2 led  
    break;
    case 3: led(1,1,1);// enciende 3 led  
    break;
  }
}
