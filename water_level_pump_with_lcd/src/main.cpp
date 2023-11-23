#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0X27,16,2); //SCL A5, SDA A4

const int trig = 2;
const int echo = 3;
const int relay = 4;

int measureDistance() 
{
   unsigned long duration;
   int distance;
   delay(50);
   digitalWrite(trig, 0);
   delayMicroseconds(2);
   digitalWrite(trig,1); 
   duration = pulseIn(echo, HIGH);
   distance = int(duration/2/29.412);
   return (distance);
}

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);

  digitalWrite(relay, 0);

  lcd.init();                    
  lcd.backlight(); 
}

void loop() {
  int value = measureDistance();
  Serial.println(value);

  if(value > 15) //the height of tank is 15cm
  {
    digitalWrite(relay, 0);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SENSOR ERROR");
    delay(500);
  }
  else
  {
    lcd.setCursor(14, 0);
    lcd.print("  ");
    lcd.setCursor(0, 0);
    lcd.print("Muc nuoc (cm): ");
    lcd.setCursor(14, 0);
    lcd.print(15 - value);

    if (value > 10)
    {
      digitalWrite(relay, 1);
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("DANG BOM NUOC");
      //delay(5000);
    }

    if (value <= 5)
    {
      digitalWrite(relay, 0);
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("NGUNG BOM NUOC");
      //delay(5000);
    }

    delay(500);
  }
}