//https://teachablemachine.withgoogle.com/models/So1ES25Db/
//https://tm-arduino.fogeinator.repl.co/


String val;     // Data received from serial port

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows


void setup() {
  Serial.begin(9600);
  lcd.init(); 
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Color Detector");
  if (Serial.available()) {
    // If data is available to read,
    val = Serial.readStringUntil('\n');
    val.trim();
    Serial.println(val);  
  }
  if (val == "Red"){
    lcd.setCursor(0,1);
    lcd.print("Red");
    Serial.println("Red");
  }
  else if (val == "Green"){
    lcd.setCursor(0,1);
    lcd.print("Green");
    Serial.println("Green");
  }
  else if (val == "Blue"){
    lcd.setCursor(0,1);
    lcd.print("Blue");
    Serial.println("Blue");
  }
  else if (val == "Other"){
    lcd.setCursor(0,1);
    lcd.print("Others");
  }
  delay(300);
  lcd.clear();
}
