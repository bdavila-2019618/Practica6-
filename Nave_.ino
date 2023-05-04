/*
 * Fundacion Kinal
 * CENTRO EDUCATIVO TECNICO LABORAL KINAL
 * ELECTRONICA
 * EB5AM
 * Taller de Electronica Digital 
 * Byron Dávila
 * 2019618
*/

#include <LiquidCrystal.h>

#define RS 12
#define Enable 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2
#define TRIG 8
#define ECO 7
#define BUZZ 6
long DISTANCIA;
int PERSONAS = -1;

LiquidCrystal LCD_DAVILA(RS, Enable, D4, D5, D6, D7); 

byte ninoConBrazoArriba[] = {
  B01110,
  B01110,
  B01110,
  B10101,
  B01110,
  B00100,
  B01010,
  B00000
};

byte ninoConBrazoAbajo[] = {
  B01110,
  B01110,
  B01110,
  B00100,
  B01110,
  B10101,
  B01110,
  B10001
};

void setup(){
  for(int i = 0; i <=16; i++){
   pinMode(i,OUTPUT);
}
   pinMode(TRIG, OUTPUT);
   pinMode(ECO, INPUT);
   pinMode(BUZZ, OUTPUT);
   LCD_DAVILA.begin(16,2); 
   LCD_DAVILA.createChar(1,ninoConBrazoAbajo);
   LCD_DAVILA.createChar(2,ninoConBrazoArriba);
   LCD_DAVILA.setCursor(0,0); 
   LCD_DAVILA.print("HUMANOS");
}
void loop(){
  MEDICION();
  Limitepers();
}
int MEDICION(){
  long I; 
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIG, LOW);
  I = pulseIn(ECO, HIGH);
  DISTANCIA = I/58.2; 
  delay(100);
  return DISTANCIA;
  }

 void Limitepers(){
    if(DISTANCIA >= 2 && DISTANCIA <=6){
    PERSONAS = PERSONAS + 1;
      }

    switch(PERSONAS){
     case 1:
      LCD_DAVILA.setCursor(0,0);
      LCD_DAVILA.print("HUMANOS"); 
      LCD_DAVILA.setCursor(PERSONAS-1,1); 
      LCD_DAVILA.write(1);
      delay(300);
      break;

     case 2:
      LCD_DAVILA.setCursor(0,0);
      LCD_DAVILA.print("HUMANOS");
      LCD_DAVILA.setCursor(PERSONAS-1,1); 
      LCD_DAVILA.write(1);
      delay(300);
      break;

     case 3:
      LCD_DAVILA.setCursor(0,0);
      LCD_DAVILA.print("HUMANOS");
      LCD_DAVILA.setCursor(PERSONAS-1,1); 
      LCD_DAVILA.write(1);
      delay(300);
      break;

     case 4:
      LCD_DAVILA.setCursor(0,0);
      LCD_DAVILA.print("HUMANOS");
      LCD_DAVILA.setCursor(PERSONAS-1,1); 
      LCD_DAVILA.write(1);
      delay(300);
      break;

      case 5:
      LCD_DAVILA.setCursor(0,0);
      LCD_DAVILA.print("HUMANOS");
      LCD_DAVILA.setCursor(PERSONAS-1,1); 
      LCD_DAVILA.write(1);
      delay(300);
      break;

      case 6:
      LCD_DAVILA.setCursor(0,0);
      LCD_DAVILA.print("HUMANOS");
      LCD_DAVILA.setCursor(PERSONAS-1,1); 
      LCD_DAVILA.write(1);
      delay(300);
      break;
      case 7:
      LCD_DAVILA.setCursor(0,0);
      LCD_DAVILA.print("HUMANOS");
      LCD_DAVILA.setCursor(PERSONAS-1,1); 
      LCD_DAVILA.write(1);
      delay(300);
      break;
      case 8:
      LCD_DAVILA.setCursor(0,0);
      LCD_DAVILA.print("HUMANOS");
      LCD_DAVILA.setCursor(PERSONAS-1,1); 
      LCD_DAVILA.write(1);
      delay(300);
      break;

      case 9:
      LCD_DAVILA.setCursor(0,0);
      LCD_DAVILA.print("HUMANOS");
      LCD_DAVILA.setCursor(PERSONAS-1,1); 
      LCD_DAVILA.write(1);
      delay(300);
      break;

      case 10:
      LCD_DAVILA.setCursor(0,0);
      LCD_DAVILA.print("HUMANOS");
      LCD_DAVILA.setCursor(PERSONAS-1,1); 
      LCD_DAVILA.write(1);
      delay(300);
      break;

      case 11:
      LCD_DAVILA.setCursor(0,0);
      LCD_DAVILA.print("HUMANOS");
      LCD_DAVILA.setCursor(PERSONAS-1,1); 
      LCD_DAVILA.write(1);
      delay(300);
      break;
      case 12:
      LCD_DAVILA.setCursor(0,0);
      LCD_DAVILA.print("HUMANOS");
      LCD_DAVILA.setCursor(PERSONAS-1,1); 
      LCD_DAVILA.write(1);
      delay(300);
      break;
      case 13:
      LCD_DAVILA.setCursor(0,0);
      LCD_DAVILA.print("HUMANOS");
      LCD_DAVILA.setCursor(PERSONAS-1,1); 
      LCD_DAVILA.write(1);
      delay(300);
      break;
      case 14:
      LCD_DAVILA.setCursor(0,0);
      LCD_DAVILA.print("HUMANOS");
      LCD_DAVILA.setCursor(PERSONAS-1,1); 
      LCD_DAVILA.write(1);
      delay(300);
      break;
      case 15:
      LCD_DAVILA.setCursor(0,0);
      LCD_DAVILA.print("HUMANOS");
      LCD_DAVILA.setCursor(PERSONAS-1,1); 
      LCD_DAVILA.write(1);
      delay(300);
      break;
      case 16:
      LCD_DAVILA.setCursor(0,0);
      LCD_DAVILA.print("ALCANZADO");
      LCD_DAVILA.setCursor(PERSONAS-1,1); 
      LCD_DAVILA.write(1);
      break;
    }
      if(PERSONAS > 17){
      LimiteMAX();
      }
      }
void LimiteMAX(){
     tone(BUZZ, 523);
     LCD_DAVILA.setCursor(0,1);
      LCD_DAVILA.write(2);
      LCD_DAVILA.write(1);
      LCD_DAVILA.write(2);
      LCD_DAVILA.write(1);
      LCD_DAVILA.write(2);
      LCD_DAVILA.write(1);
      LCD_DAVILA.write(2);
      LCD_DAVILA.write(1);
      LCD_DAVILA.write(2);
      LCD_DAVILA.write(1);
      LCD_DAVILA.write(2);
      LCD_DAVILA.write(1);
      LCD_DAVILA.write(2);
      LCD_DAVILA.write(1);
      LCD_DAVILA.write(2);
      LCD_DAVILA.write(1); 
      delay(500);
      LCD_DAVILA.setCursor(0,1);
      LCD_DAVILA.write(1);
      LCD_DAVILA.write(2);
      LCD_DAVILA.write(1);
      LCD_DAVILA.write(2);
      LCD_DAVILA.write(1);
      LCD_DAVILA.write(2);
      LCD_DAVILA.write(1);
      LCD_DAVILA.write(2);
      LCD_DAVILA.write(1);
      LCD_DAVILA.write(2);
      LCD_DAVILA.write(1);
      LCD_DAVILA.write(2);
      LCD_DAVILA.write(1);
      LCD_DAVILA.write(2);
      LCD_DAVILA.write(1);
      LCD_DAVILA.write(2);
      delay(500);
}
      
 
