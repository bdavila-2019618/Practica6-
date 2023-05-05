/*
 * Fundacion Kinal
 * CENTRO EDUCATIVO TECNICO LABORAL KINAL
 * ELECTRONICA 
 * EB5AM
 * Taller de Electronica Digital 
 * Byron Renato Dávila Santiago
 * 2019618
 */
 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 

#define D_LCD 0x27
#define Filas 2
#define Columnas 16
#define TRIG A0
#define ECO A1
#define BUZZ 12
#define L1 2
#define L2 3
#define L3 4
#define L4 5
#define L5 6
#define L6 7
#define L7 8
#define L8 9
#define L9 10
#define L10 11
int DISTANCIA;
int i;

LiquidCrystal_I2C LCD_DAVILA(D_LCD, Columnas, Filas);

int CONFIGURACIONESled(){
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  pinMode(L7, OUTPUT);
  pinMode(L8, OUTPUT);
  pinMode(L9, OUTPUT);
  pinMode(L10, OUTPUT);
  
  
  }

void setup()
{
  CONFIGURACIONESled();
  for(i=2; i<=11;i++){
  }
  pinMode(BUZZ ,OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  LCD_DAVILA.init();
  LCD_DAVILA.backlight();
}


void loop()
{
  MEDICION();
  Alarma();
}
int MEDICION(){
  long Duracion;
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  Duracion = pulseIn(ECO, HIGH);
  DISTANCIA = Duracion/59;
  delay(50);
  return DISTANCIA;
}
int Alarma(){
   if( DISTANCIA > 45){
    LCD_DAVILA.setCursor(0,0);
    LCD_DAVILA.print(" FUERA DE PELIGRO ");
    LCD_DAVILA.setCursor(0,1);
    LCD_DAVILA.print(" PROPIEDAD ");
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
  }
   else if( DISTANCIA < 45 && DISTANCIA > 30){
    LCD_DAVILA.setCursor(0,0);
    LCD_DAVILA.print(" APROX A ");
    LCD_DAVILA.setCursor(0,1);
    LCD_DAVILA.print("PROPIEDAD ");
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
  }
 else if( DISTANCIA < 30 && DISTANCIA > 15){
    LCD_DAVILA.setCursor(0,0);
    LCD_DAVILA.print(" ATENTO ");
    LCD_DAVILA.setCursor(0,1);
    LCD_DAVILA.print("PROPIEDAD ");
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
    tone(BUZZ, 523);
    delay(2000);
    noTone(BUZZ);
  }


 else if( DISTANCIA < 15 && DISTANCIA > 0){
    LCD_DAVILA.setCursor(0,0);
    LCD_DAVILA.print(" ASALTANDO ");
    LCD_DAVILA.setCursor(0,1);
    LCD_DAVILA.print("PROPIEDAD");
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
    tone(BUZZ, 523);
    delay(2000);
    noTone(BUZZ);
 }
    else {
    noTone(BUZZ);
 }
    return 0;
 }
