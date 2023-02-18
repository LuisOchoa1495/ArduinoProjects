#include<Keypad.h> // GESTOR DE LIBRERIAS
#include<Servo.h> 
#include<LiquidCrystal.h>
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
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
  lcd.begin(16,2);
  pinMode(led_verde,OUTPUT);
  pinMode(led_rojo,OUTPUT);
  servo_motor.attach(12);
  
}

void loop(){  
  lcd.setCursor(0,0);
  lcd.print("INGRESE CLAVE:");
  tecla=teclado.getKey();
  delay(100);
  if(tecla){
    clave[index]=tecla; // 456
    index++;
    lcd.setCursor(0,1);
    lcd.print(clave);
    delay(100);

  }  
if(index==3){
    if(!strcmp(clave,clave_ok)){//si compara exictosamente 0 = false & 1=true
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("CORRECTA");
        digitalWrite(led_verde,HIGH);
        servo_motor.write(0);
        delay(5000);
        servo_motor.write(90);
        digitalWrite(led_verde,LOW);
        index=0;
        strcpy(clave,"   ");
        lcd.clear();
    }
    else{
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("INCORRECTA");
        digitalWrite(led_rojo,HIGH);
        delay(2000);
        digitalWrite(led_rojo,LOW);       
        index=0;
    strcpy(clave,"   ");
        lcd.clear();
    }
    
  }
}
