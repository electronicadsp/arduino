/*
  Librería LiquidCrystal - Hello World

  Demostración del uso en display LCD 16x2.  La librería LiquidCrystal
  trabaja con todos los LCD que son compatibles con el controlador
  Hitachi HD44780.

  El ciruito:
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
   LCD R/W pin to ground
   LCD VSS pin to ground
   LCD VCC pin to 5V
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)
*/

// incluir el codigo de la librería
#include <LiquidCrystal.h>

// Inicializa la librería asociando los pines del LCD con los
//números de pines conectados al Arduino
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//creo un caracter personalizado de una carita sonriente
byte smiley[8] = {
  B10001,
  B00000,
  B00000,
  B10001,
  B10001,
  B01110,
  B00000,
};
void setup() {
  // Establesco el número de columnas y fils del LCD:
  lcd.begin(16, 2);
  //Creo el caracter personalizado en la posición 0
  lcd.createChar(0, smiley);
}

void loop() {
  // Limpio e imprimo el mensaje al LCD:
  lcd.clear();
  lcd.print(" Hello, World!");
  //Posiciono el cursor en la columna 5 y fila 2:
  lcd.setCursor(4, 1);
  //Imprimo 4 caracteres personalizados (carita sonriente):
  for (int i = 0; i < 4; i++) {
    lcd.write(byte(0));
    lcd.write(' ');
    delay(150);
  }
  delay(5000);
  lcd.clear();
  lcd.print("No display en 2s");
  delay(2000);
  //Apago el display del LCD:
  lcd.noDisplay();
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 1);
  //Imprimo sobre el LCD con el display apagado:
  lcd.print("Display");
  //Activo el display y muestro el mensaje:
  lcd.display();
  delay(5000);
  lcd.clear();
  //Imprimo mensaje con cursor titilando:
  lcd.blink();
  lcd.print("blink cursor");
  delay(5000);
  lcd.setCursor(0, 1);
  //Desactivo el cursor titilando:
  lcd.noBlink();
  lcd.print("NO blink cursor");
  delay(5000);
  // Activo el scroll automático:
  lcd.clear();
  lcd.print("Autoscroll");
  delay(2000);
  lcd.setCursor(0, 1);
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  lcd.setCursor(16, 1);
  // Activo en el display el scroll automático:
  lcd.autoscroll();
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  lcd.noAutoscroll();

  // scroll 13 posiciones a la izquierda
  // los muevo fuera de la pantalla a la izquierda:
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll una posición a la izquierda:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(200);
  }

  // scroll 29 posiciones (longitud del mensaje + longitud del display) hacia la derecha
  // los muevo fuera de la pantalla hacia la derecha:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll una posición a la derecha:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(200);
  }

  // scroll 16 posiciones (longitud de la pantalla + longitud del mensaje) hacial la derecha
  // lo muevo para centrar el mensaje:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll una posición a la izquierda:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(200);
  }

  // retardo el fin del loop 1s.:
  delay(1000);
}
