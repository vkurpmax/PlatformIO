#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo servo1;
Servo servo2;

int IN4 = 12;
const int tombol = 3;
int nilaitombol;
int countertombol = 0;

void setup() {
  pinMode(IN4, OUTPUT);
  //pinMode(8, INPUT);
  pinMode(tombol, INPUT_PULLUP);

  servo1.attach(5);
  servo2.attach(6);
  
  lcd.begin();
  lcd.setCursor(0,0);
  lcd.print("     ORANGE    ");
  lcd.setCursor(0,1);
  lcd.print("SORTING CONVEYOR ");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  PLEASE  PUSH  ");
  lcd.setCursor(0,1);
  lcd.print("  START BUTTON  ");
}

void loop() {
  pushbutton();
}

void pushbutton() {
  if (digitalRead(tombol) == LOW) {
    countertombol++;
    delay(500);
    if (countertombol == 1) {
      digitalWrite(IN4, HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("    CONVEYOR    ");
      lcd.setCursor(0,1);
      lcd.print("       ON       ");
      servo1.write(10);
    }
    if (countertombol == 2) {
      digitalWrite(IN4, LOW);
      servo1.write(105);
      servo2.write(93);
      countertombol = 0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("    CONVEYOR    ");
      lcd.setCursor(0,1);
      lcd.print("      OFF");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("     THANK     ");
      lcd.setCursor(0,1);
      lcd.print("      YOU      ");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("  PLEASE  PUSH  ");
      lcd.setCursor(0,1);
      lcd.print("  START BUTTON  ");
    }
  }
}