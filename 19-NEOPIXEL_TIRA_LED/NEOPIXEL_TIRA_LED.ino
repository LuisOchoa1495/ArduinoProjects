#include <Adafruit_NeoPixel.h>
#define PIN 2   // PIN NEOPIXEL
#define NUMPIXELS 12 // NUMERO DE LA CADENA DE NEOPIXEL

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 200; // TIEMPO EN MILISEGUNDOS
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setup() {
  // INICIALIZAR LIBRERIA NEOPIXEL
  pixels.begin();
}

void loop() {
  AsignarColor();
  for (int i=0; i < NUMPIXELS; i++) {
    // Asignaremos el color RGB 0,0,0 - 255,255,255
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));
    // mostraremos el color en la tira rgb
    pixels.show();
    // delay de recorrido
    delay(delayval);
  }
}

// ESTABLECEMOS VALORES ALEATORIOS
void AsignarColor(){
  redColor = random(0, 255);
  greenColor = random(0,255);
  blueColor = random(0, 255);
}
