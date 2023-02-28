//Sensor ultrasonido
int trig=11;
int echo=10;
int duracion;
float distancia;
//Led rgb
int pinLedR = 5;  // pin Rojo del led RGB
int pinLedV = 4;  // pin Verde del led RGB
int pinLedA = 3;  // pin Azul del led RGB

void setup()
{
  pinMode(pinLedR, OUTPUT);    
  pinMode(pinLedV, OUTPUT);    
  pinMode(pinLedA, OUTPUT);    
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop()
{	
  digitalWrite(trig,HIGH);
  delay(1);
  digitalWrite(trig,LOW);
  duracion=pulseIn(echo,HIGH);
  distancia=duracion/58.2;
  Serial.println(distancia+ String("cm"));
  if(distancia<30){
  	color(255,0,0);
  }
  else{
    color(0,0,255);
  }
  delay(1000);
}

void color (int rojo, int verde, int azul)
{
  analogWrite(pinLedR, rojo);
  analogWrite(pinLedV, verde);
  analogWrite(pinLedA, azul);
}
