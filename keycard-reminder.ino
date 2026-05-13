#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#define PIR 5
#define buzzerPin 2
bool PIRState;

void setup() {
  Serial.begin(115200);
  Wire.begin(17, 16); // SDA, SCL
  lcd.init();
  lcd.backlight();
  pinMode(PIR, INPUT);  // INPUT not INPUT_PULLDOWN
  pinMode(buzzerPin,OUTPUT);
}
void loop() {
  PIRState = digitalRead(PIR);
  Serial.println(PIRState);

  if(PIRState == 1){
    lcd.backlight();
    lcd.setCursor(0, 0);
    digitalWrite(buzzerPin,HIGH);
    lcd.print("Take your");
    lcd.setCursor(0, 1);
    lcd.print("keycard!!");
    digitalWrite(buzzerPin,LOW);
    delay(10000);
    lcd.clear();
    lcd.noBacklight();
  }
}
