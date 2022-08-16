#include<Keypad.h> // GESTOR DE LIBRERIAS
#include<Servo.h> 
Servo servo_motor; // servomotor
const byte filas=4;
const byte columnas=4;
char keys[filas][columnas]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pinesFilas[filas]={9,8,7,6};
byte pinesColumnas[columnas]={5,4,3,2};

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas,filas,columnas);
char tecla;
char clave[4]; // 0 1 2 3
char clave_ok[4]="123";
byte index=0;
int led_verde=10;
int led_rojo=11;

void setup(){
  pinMode(led_verde,OUTPUT);
  pinMode(led_rojo,OUTPUT);
  servo_motor.attach(12);
  Serial.begin(9600);
  Serial.println("ingrese clave:");
}

void loop(){ 
  tecla=teclado.getKey();
  delay(100);
  if(tecla){
  clave[index]=tecla; // 456
  index++;
  Serial.print(tecla);
}  
if(index==3){
/*La función strcmp:
Sirve para comparar la cadena cadena1 con la cadena2 . Devuelve el valor devuelve 0 si son iguales. 
Devuelve menor que cero si cadena1 es menor que cadena2*/
    if(!strcmp(clave,clave_ok)){//si compara exictosamente 0 = false & 1=true
        Serial.print(" Correcta");
        Serial.println("");
        digitalWrite(led_verde,HIGH);
        servo_motor.write(0);
        delay(5000);
        servo_motor.write(90);
        digitalWrite(led_verde,LOW);
        index=0;
    }
    else{
      Serial.print(" Incorrecta");
        Serial.println("");
        digitalWrite(led_rojo,HIGH);
        delay(2000);
        digitalWrite(led_rojo,LOW);       
        index=0;
    }
  }
}
