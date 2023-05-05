#include <OneWire.h>                
#include <DallasTemperature.h>
#include <Wire.h>    
#include <LiquidCrystal_I2C.h>

#define Direccion_LCD 0x27
#define FILAS 2
#define COLUMNAS 16
#define Pin_de_datos 2
#define D1 3
#define D2 4
#define D3 5

int Fahrenheit;
int OFahrenheit();
int Celsius;
int ICelsius();
void LCD_BYRON();
byte Termometro[] = {
  B11111,
  B01010,
  B01010,
  B01010,
  B01010,
  B01010,
  B01110,
  B00000
};
byte Signo_de_grados[] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte Copo_de_Nieve[] = {
  B10101,
  B01110,
  B00100,
  B11111,
  B00100,
  B01110,
  B10101,
  B00000
};
byte Fuego[] = {
  B10100,
  B01010,
  B01111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};
byte Persona[] = {
  B00100,
  B01110,
  B01110,
  B11111,
  B11111,
  B01110,
  B01110,
  B00000
};
OneWire ourWire(2);
DallasTemperature SENSOR(&ourWire); 
LiquidCrystal_I2C LCD_DAVILA(Direccion_LCD, COLUMNAS, FILAS);
void setup() {
  delay(1000);
  Serial.begin(9600);
  SENSOR.begin();
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  LCD_DAVILA.begin(16, 2);
  LCD_DAVILA.init();
  LCD_DAVILA.backlight();
  LCD_DAVILA.createChar(1, Termometro);
  LCD_DAVILA.write(1);
  LCD_DAVILA.createChar(2, Signo_de_grados);
  LCD_DAVILA.write(2);
  LCD_DAVILA.createChar(3, Copo_de_Nieve);
  LCD_DAVILA.write(3);
  LCD_DAVILA.createChar(4, Fuego);
  LCD_DAVILA.write(4);
  LCD_DAVILA.createChar(5, Persona);
  LCD_DAVILA.write(5);
}

void loop() 
{
   LCD_BYRON(); 
}
 int ICelsius(){
  SENSOR.requestTemperatures();
  int C = SENSOR.getTempCByIndex(0); 
  return C;
}
 int OFahrenheit(){
  SENSOR.requestTemperatures();
  int F = SENSOR.getTempFByIndex(0); 
  return F;
}

 void LCD_BYRON(){
 Fahrenheit = OFahrenheit();
 Celsius = ICelsius();
  if(Celsius > 30){
    LCD_DAVILA.setCursor(0,0);
    LCD_DAVILA.print("MEDIDOR");
    LCD_DAVILA.setCursor(10,0);
    LCD_DAVILA.write(1);
    LCD_DAVILA.setCursor(0,1);
    LCD_DAVILA.print(SENSOR.getTempCByIndex(0));
    LCD_DAVILA.setCursor(5,1);
    LCD_DAVILA.write(2);
    LCD_DAVILA.setCursor(6,1);
    LCD_DAVILA.print("C");
    LCD_DAVILA.setCursor(7,1);
    LCD_DAVILA.write(4);
    LCD_DAVILA.setCursor(9,1);
    LCD_DAVILA.print(SENSOR.getTempFByIndex(0));
    LCD_DAVILA.setCursor(14,1);
    LCD_DAVILA.write(2);
    LCD_DAVILA.setCursor(15,1);
    LCD_DAVILA.print("F");
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    }
  if(Celsius > 15 && Celsius < 30){
    LCD_DAVILA.setCursor(0,0);
    LCD_DAVILA.print("MEDIDOR");
    LCD_DAVILA.setCursor(10,0);
    LCD_DAVILA.write(1);
    LCD_DAVILA.setCursor(0,1);
    LCD_DAVILA.print(SENSOR.getTempCByIndex(0));
    LCD_DAVILA.setCursor(5,1);
    LCD_DAVILA.write(2);
    LCD_DAVILA.setCursor(6,1);
    LCD_DAVILA.print("C");
    LCD_DAVILA.setCursor(7,1);
    LCD_DAVILA.write(5);
    LCD_DAVILA.setCursor(9,1);
    LCD_DAVILA.print(SENSOR.getTempFByIndex(0));
    LCD_DAVILA.setCursor(14,1);
    LCD_DAVILA.write(2);
    LCD_DAVILA.setCursor(15,1);
    LCD_DAVILA.print("F");
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW); 

  }
  if(Celsius < 15 ){
    LCD_DAVILA.setCursor(0,0);
    LCD_DAVILA.print("MEDIDOR");
    LCD_DAVILA.setCursor(10,0);
    LCD_DAVILA.write(1);
    LCD_DAVILA.setCursor(0,1);
    LCD_DAVILA.print(SENSOR.getTempCByIndex(0));
    LCD_DAVILA.setCursor(5,1);
    LCD_DAVILA.write(2);
    LCD_DAVILA.setCursor(6,1);
    LCD_DAVILA.print("C");
    LCD_DAVILA.setCursor(7,1);
    LCD_DAVILA.write(3);
    LCD_DAVILA.setCursor(9,1);
    LCD_DAVILA.print(SENSOR.getTempFByIndex(0));
    LCD_DAVILA.setCursor(14,1);
    LCD_DAVILA.write(2);
    LCD_DAVILA.setCursor(15,1);
    LCD_DAVILA.print("F");
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH); 
  }
  }
