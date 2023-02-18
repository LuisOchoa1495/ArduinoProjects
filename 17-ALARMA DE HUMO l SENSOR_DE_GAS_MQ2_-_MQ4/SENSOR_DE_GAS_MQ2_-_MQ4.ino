int sensor_gas;
int buzzer=12;
int led=6;
void setup()
{
 
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
 sensor_gas=analogRead(A0);
 Serial.println(sensor_gas);
  if(sensor_gas>=250){
    digitalWrite(led,HIGH);
    delay(500);  
    tone(buzzer,500,100);
  delay(2000);
    digitalWrite(led,LOW);
  }
}
