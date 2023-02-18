#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int lectura;
float voltaje,temperatura;

void setup() {
lcd.begin(16,2);
}
  
void loop() {
lcd.clear();
lcd.setCursor(0,0);
lcd.print("TEMPERATURA:");

lectura=analogRead(A0);
voltaje=5.0/1024*lectura;
temperatura=voltaje*100-50; // tmp36
//temperatura=voltaje*100;  SENSOR LM35
lcd.setCursor(0,1);
lcd.print(temperatura +String(" C"));
delay(1000);
}
