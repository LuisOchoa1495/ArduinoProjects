#include <Servo.h> 
Servo Servo1;
Servo Servo2;
# define flexPin1 A0
# define flexPin2 A1

void setup() 
{ 
  Servo2.attach(11);
  Servo1.attach(12);
  Serial.begin(9600);
} 

void loop() 
{ 
  int flexValor1,flexValor2;
  int servoPosicion1,servoPosicion2;
  
  flexValor1 = analogRead(flexPin1);
  servoPosicion1 = map(flexValor1, 770, 950, 0, 180); 
  Servo1.write(servoPosicion1);
  
  flexValor2 = analogRead(flexPin2);
  servoPosicion2 = map(flexValor2, 770, 950, 0, 180); 
  Servo2.write(servoPosicion2);
  
  delay(20);
}
