#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// IR sensor pin
const int irSensorPin = 2;

void setup() {
  // Initialize the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);
  lcd.backlight();
  
  // Initialize the IR sensor pin as input
  pinMode(irSensorPin, INPUT);
}

void loop() {
  // Read the value from the IR sensor
  int sensorValue = digitalRead(irSensorPin);
  
  // Clear the previous content on the LCD
  lcd.clear();
  
  if (sensorValue == LOW) {
    // Object detected
    lcd.setCursor(0, 0);
    lcd.print("Object detected");
  } else {
    // No object detected
    lcd.setCursor(0, 0);
    lcd.print("Object detection");
    lcd.setCursor(0, 1);
    lcd.print("system");
  }
  
  // Small delay to prevent flickering
  delay(500);
}
