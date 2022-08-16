#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int trig=10;
int echo=9;
int duracion;
float distancia;
  
void setup() {
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("DISTANCIA:");
}
  
void loop() {
digitalWrite(trig,HIGH);
delay(1);
digitalWrite(trig,LOW);
duracion=pulseIn(echo,HIGH);
distancia=duracion/58.2;
lcd.setCursor(0,1);
lcd.print(distancia);
lcd.setCursor(5,1);
lcd.print("cm");
}
