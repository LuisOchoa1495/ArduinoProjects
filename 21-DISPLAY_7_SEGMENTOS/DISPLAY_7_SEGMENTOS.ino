void setup()
{
  for(int i=2;i<=8;i++){
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  for(int i=0; i<=9;i++){
  view(i);
  delay(500);
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

void view(int n){
    switch(n){
    case 0: display(1,1,1,1,1,1,0);// numero 0  
    break;
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
    case 7: display(1,1,1,0,0,0,0);// numero 7  
    break;
    case 8: display(1,1,1,1,1,1,1);// numero 8  
    break;
    case 9: display(1,1,1,1,0,1,1);// numero 9  
    break;
  }
}
