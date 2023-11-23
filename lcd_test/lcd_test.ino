#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0X27,16,2); //SCL A5 SDA A4
int num=0;

void setup()
{
  lcd.init();                    
  lcd.backlight(); 
}

void loop()
{
  lcd.setCursor(2,0);
  lcd.print("WELCOME");
  lcd.setCursor(0,1);
  lcd.print("Counting:  "); 
  
  lcd.setCursor(10,1);
  lcd.print(num);
  num++;
  if(num >= 10)
  {
    num=0;
  }
  delay (1000);
  lcd.clear();
}