#include <LiquidCrystal.h> /* Incluir biblioteca del LCD*/
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);  /*pines para el lcd 12,11,5,4,3,2 */
int SensorPin = A0; /* Declaramos la entrada para lo que será la entrada analógica A0 la                                                            Nombraremos "SensorPin"*/
int Suelo = 0;

void setup() {
lcd.begin (16, 2); /*columnas y filas de lcd */
lcd.print("Humedad"); /* Titulo a mostrar */
Serial.begin(9600); /* Iniciamos el puerto serie , de esta forma podemos visualizar las lecturas en el monitor serie*/
}
void loop() {
lcd.clear();
int Suelo = analogRead(SensorPin);           //asignar los valores//
 /* Rango de medición */
Suelo = map (Suelo, 0, 876, 0,100);       /*  valores porcentuales dentro del rango */
lcd.setCursor (0, 0);  
lcd.print("Humedad"); /* Titulo a mostrar */
lcd.setCursor (0, 1);                                /* Posición inicial del texto*/
lcd.print(Suelo + String("%"));                                     //Mostrar números finales//                                     //imprimir el símbolo de porcentaje al final//
delay(1000);                                          //Espere segundos 0,1//
lcd.print("");                                          //Limpie los caracteres adicionales//
delay(1);
}
