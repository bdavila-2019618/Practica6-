/*
 * Fundacion Kinal
 * CENTRO EDUCATIVO TECNICO LABORAL KINAL
 * ELECTRONICA
 * EB5AM
 * Taller de Electronica Digital 
 * Byron Dávila
 * 2019618
*/
#include <Wire.h>    
#include <LiquidCrystal_I2C.h>

#define Direccion_LCD 0x27
#define FILAS 2
#define COLUMNAS 16
#define TRIG 11
#define ECO 12
int DISTANCIA;
long I;
LiquidCrystal_I2C LCD_DAVILA(Direccion_LCD, COLUMNAS, FILAS);
byte BLOQUE[] = {
  B00100,
  B01110,
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B01110
  };
void setup()
{
  LCD_DAVILA.begin(16, 2);
  LCD_DAVILA.createChar(1, BLOQUE);
  LCD_DAVILA.write(1);
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  LCD_DAVILA.init();
  LCD_DAVILA.backlight();
}


void loop()
{
  DIFERENCIA();
  Sensor();
}
int DIFERENCIA(){ 
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIG, LOW);
  I = pulseIn(ECO, HIGH);
  DISTANCIA = I/59;
  delay(50);
  return DISTANCIA;
}
int Sensor(){
   if( DISTANCIA > 30){
    LCD_DAVILA.setCursor(7,0);
    LCD_DAVILA.print("30");
    LCD_DAVILA.setCursor(0,1);
    LCD_DAVILA.print("     LIBRE!      ");
    LCD_DAVILA.setCursor(3,0);
    LCD_DAVILA.print("    ");
    LCD_DAVILA.setCursor(9,0);
    LCD_DAVILA.print("    ");
    LCD_DAVILA.setCursor(0,0);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.setCursor(13,0);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
  }
  if( DISTANCIA == 20 ){
    LCD_DAVILA.setCursor(7,0);
    LCD_DAVILA.print("20");
    LCD_DAVILA.setCursor(0,1);
    LCD_DAVILA.print("     PRECAUCION      ");
    LCD_DAVILA.setCursor(5,0);
    LCD_DAVILA.print("  ");
    LCD_DAVILA.setCursor(9,0);
    LCD_DAVILA.print("  ");
    LCD_DAVILA.setCursor(0,0);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.setCursor(11,0);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
  }
  if( DISTANCIA == 10){
    LCD_DAVILA.setCursor(7,0);
    LCD_DAVILA.print("10");
    LCD_DAVILA.setCursor(0,1);
    LCD_DAVILA.print("      PARE      ");
    LCD_DAVILA.setCursor(0,0);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.setCursor(9,0);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);
    LCD_DAVILA.write(1);

  }
  return 0;
 }
      
 
