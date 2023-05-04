/*
 * Fundacion Kinal
 * CENTRO EDUCATIVO TECNICO LABORAL KINAL
 * ELECTRONICA 
 * EB5AM
 * Taller de Electronica Digital 
 * Byron Renato Dávila Santiago
 * 2019618
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd_davila(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

byte Nave[] = {
  B00000,
  B11100,
  B01110,
  B11111,
  B11110,
  B01110,
  B11100,
  B00000
};
void setup() {
  lcd_davila.begin(16, 2);
  lcd_davila.createChar(0,Nave);
}

void loop() {
  for (int j = 0; j < 16; j++) {
    for (int i = 0; i < 4; i++) {
      lcd_davila.clear();
      lcd_davila.setCursor(j, i);
      lcd_davila.write(' ');
    }
    lcd_davila.setCursor(j, 0);
    lcd_davila.write(byte(0));
    delay(100);
  }
}
