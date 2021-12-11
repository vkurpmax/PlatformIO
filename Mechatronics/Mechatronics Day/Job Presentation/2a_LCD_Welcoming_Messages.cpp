#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("3A MEKATRONIKA");
   lcd.setCursor(2,1);
  lcd.print("KELOMPOK 2");
  delay(3000);
  lcd.clear();
   lcd.setCursor(0,0);
  lcd.print("MECHATRONICS DAY ");
   lcd.setCursor(2,1);
  lcd.print(" >CONVEYOR< ");
  delay(3000);
   lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("1.Putu Herdy K ");
 lcd.setCursor(0,1);
 lcd.print("2.Agus");
 delay(3000);
   lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("3.Aan Darmawan");
 lcd.setCursor(0,1);
 lcd.print("4.Indri Puspita");
 delay(3000);
   lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("5.Risnawati");
 delay(1000);
  lcd.clear();

}


void loop()
{
 
}