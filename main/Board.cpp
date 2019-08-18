#include <Adafruit_NeoPixel.h>
#include "Board.h"

Board::Board(int pixelCount, int pixelPin) {
  this->controller = Adafruit_NeoPixel(pixelCount, pixelPin, NEO_GRB + NEO_KHZ800);
  this->isSetup = false;
}

void Board::setup() {
  this->controller.begin();
  this->controller.setBrightness(255);
  this->isSetup = true;
}

void Board::setPixelColor(int location, uint32_t color) {
  this->controller.setPixelColor(location, color);
  this->controller.show();
}
