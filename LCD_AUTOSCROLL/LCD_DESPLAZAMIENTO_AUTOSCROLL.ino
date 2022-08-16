  #include <LiquidCrystal.h>
  LiquidCrystal lcd(12,11,5,4,3,2);
  
  void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("HELLO WORLD :)");
  lcd.setCursor(1,1);
  lcd.print("   FOLLOW ME ON TIK TOK - INSTAGRAM");
  delay(2000);
  }
  
  void loop() {
  lcd.setCursor(16,1);
  lcd.autoscroll();
  lcd.print(" ");
  delay(700);
  }
