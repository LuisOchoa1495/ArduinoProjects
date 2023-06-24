#include <SPI.h>
#include <MFRC522.h>
#include<Servo.h> // servomotor

const int RST_PIN = 9;        // Pin 9 para el reset del RC522
const int SS_PIN = 10;        // Pin 10 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Crear instancia del MFRC522
Servo servo_motor; // servomotor
byte validKey1[4] = { 0x63, 0x46, 0xA3, 0x05 };  // Ejemplo de clave valida

//Función para comparar dos vectores
bool isEqualArray(byte* arrayA, byte* arrayB, int length)
{
  for (int index = 0; index < length; index++)
  {
    if (arrayA[index] != arrayB[index]) return false;
  }
  return true;
}

void setup() {
  Serial.begin(9600); // Iniciar serial
  SPI.begin();        // Iniciar SPI
  mfrc522.PCD_Init(); // Iniciar MFRC522
  servo_motor.attach(6);//PIN SERVO
  
}

void loop() {
  // Detectar tarjeta
  if (mfrc522.PICC_IsNewCardPresent())
  {
    //Seleccionamos una tarjeta
    if (mfrc522.PICC_ReadCardSerial())
    {
      // Comparar ID con las claves válidas
      if (isEqualArray(mfrc522.uid.uidByte, validKey1, 4)){
        servo_motor.write(180);
        Serial.println("Tarjeta valida");
        delay(5000);
        servo_motor.write(90);
      }
      else{
        Serial.println("Tarjeta invalida");
      }
      // Finalizar lectura actual
      mfrc522.PICC_HaltA();
    }
  }
  delay(250);

}
