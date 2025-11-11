#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int i=0;
char s[] = "Welcome to MCIOT Lab!";


void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0,0);
  for(i=0 ; s[i]!='\0' ; i++) {
    lcd.print(s[i]);
  }
  delay(2000);
  lcd.clear();
}
