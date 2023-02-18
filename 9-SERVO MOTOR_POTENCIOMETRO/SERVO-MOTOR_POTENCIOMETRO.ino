#include<Servo.h>
Servo servo_motor;
int potenciometro=0;
int val;
void setup(){
  servo_motor.attach(7);
}

void loop() {
val=analogRead(potenciometro);//0-1023         0-180
val=map(val,0,1023,0,180);
servo_motor.write(val);
delay(15);
}
