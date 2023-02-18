int pulsador=9;
int led1=A0;
int led2=A1;
int led3=A2;
int led4=A3;
int led5=A4;
int led6=A5;
int random_led;
int random_display;
void setup()
{
  for(int i=2;i<=8;i++){
    pinMode(i, OUTPUT);
  }  
  for(int i=1;i<=6;i++){
    String a="led";
    pinMode(a.concat(i), OUTPUT);
  }
  pinMode(pulsador, INPUT);
  Serial.begin(9600);
 
}

void loop()
{
  if(digitalRead(pulsador)==LOW){
  	random_led=random(1,7); // valores aleatorios 1 - 6
    random_display=random(1,7);
    led_encendido(random_led);
    view_display(random_display);
    
    if(random_led == random_display){
    	Serial.println("YOU WIN");
      	delay(2000);
    }
    else{
    	Serial.println("YOU LOSE");
      	delay(2000);
    }
  }
}

void led(int a, int b, int c, int d, int e,int f){ // HIGH = 1 , LOW =0
	digitalWrite(led1,a);
    digitalWrite(led2,b);
    digitalWrite(led3,c);
    digitalWrite(led4,d);
    digitalWrite(led5,e);
    digitalWrite(led6,f); 
}

void led_encendido(int n){
  switch(n){
    case 1: led(1,0,0,0,0,0);// numero 1  
    break;
    case 2: led(1,1,0,0,0,0);// numero 2  
    break;
    case 3: led(1,1,1,0,0,0);// numero 3  
    break;
    case 4: led(1,1,1,1,0,0);// numero 4  
    break;
    case 5: led(1,1,1,1,1,0);// numero 5  
    break;
   	case 6: led(1,1,1,1,1,1);// numero 6  
    break;
  }
}

void display(int a, int b, int c, int d, int e,int f, int g){
	digitalWrite(2,a);
    digitalWrite(3,b);
    digitalWrite(4,c);
    digitalWrite(5,d);
    digitalWrite(6,e);
    digitalWrite(7,f);
    digitalWrite(8,g);  
}

void view_display(int n){
  switch(n){
    case 1: display(0,1,1,0,0,0,0);// numero 1  
    break;
    case 2: display(1,1,0,1,1,0,1);// numero 2  
    break;
    case 3: display(1,1,1,1,0,0,1);// numero 3  
    break;
    case 4: display(0,1,1,0,0,1,1);// numero 4  
    break;
    case 5: display(1,0,1,1,0,1,1);// numero 5  
    break;
   	case 6: display(1,0,1,1,1,1,1);// numero 6  
    break;
  }
}
