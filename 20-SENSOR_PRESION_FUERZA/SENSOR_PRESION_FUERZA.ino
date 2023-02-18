int sensor_fuerza= A0;
int led=11;
int lectura;
int brillo;
void setup()
{ 
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
// La Resistencia es igual a la lectura del sensor (Analog 0)
lectura = analogRead(sensor_fuerza); 
Serial.print("Lectura Analogica = ");
Serial.println(lectura); 
// Cambiar el rango de la lectura analógica (0-1023)
// Utilizamos en analogWrite 8 bits (0-255) configurados en el map
brillo = map(lectura, 0, 1023, 0, 255);
analogWrite(led, brillo); 
delay(100); //Cien “ms” de espera en cada lectura
}
