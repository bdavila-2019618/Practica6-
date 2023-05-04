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
#define D7 2
#define D6 3
#define D5 4
#define D4 5
#define Enable 11
#define RS 12

 LiquidCrystal LCD_DAVILA(RS, Enable, D4, D5, D6, D7);
void setup() {
  LCD_DAVILA.begin(16,2);
  LCD_DAVILA.setCursor(0,0); 
  LCD_DAVILA.print("BYRON DAVILA");
  LCD_DAVILA.setCursor(0,1);
  LCD_DAVILA.print("2019618");
}


void loop() {  
  }
    
