#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
#define DHTPIN 9 // conectamos el sensor al pin 9
#define DHTTYPE DHT11 // 22
float temperatura;
float humedad;
DHT dht (DHTPIN, DHTTYPE);
void setup(){  
lcd.init();
lcd.backlight();
lcd.begin(16,2);  
dht.begin();
}

void loop(){
    lcd.clear();
    temperatura=dht.readTemperature();
    humedad=dht.readHumidity();
    //TEMPERATURA
    lcd.setCursor(0,0);
    lcd.print("TEMPERAT: "); 
    lcd.print(temperatura);
    lcd.print(" C");
    //HUMEDAD
    lcd.setCursor(0,1);
    lcd.print("HUMEDAD: ");  
    lcd.print(humedad); 
    lcd.print(" %");
    delay(2000);            
}
