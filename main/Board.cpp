#include <Adafruit_NeoPixel.h>
#include "Board.h"

Board::Board(Adafruit_NeoPixel &controller) {
  _controller = controller;
  _setup = false;
}

void Board::setup() {
  _controller.begin();
  _controller.setBrightness(255);
  _setup = true;
}

void Board::setPixelColor(int location, uint32_t color) {
  _controller.setPixelColor(location, color);
  _controller.show();
}

void Board::show() {
  // _controller.show();
}