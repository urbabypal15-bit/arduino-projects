#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C display(0x27, 16, 2);


void setup() {
  Serial.begin(9600);
  display.init();
  display.backlight();
  display.setCursor(4,0);
  display.print("Kimberly");
  display.setCursor(2,1);
  display.print("Arduino Uno");


}

void loop() {
  

}
