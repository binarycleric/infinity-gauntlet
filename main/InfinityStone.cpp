#include "InfinityStone.h"

InfinityStone::InfinityStone(StoneColor color, int location) {
  this->color = color;
  this->location = location;
  this->currentBrightness = 0;
}

InfinityStone::InfinityStone(const InfinityStone &stone) {
  this->color = stone.getColor();
  this->location = stone.getLocation();
}

int InfinityStone::getLocation() {
  return this->location;
}

StoneColor InfinityStone::getColor() {
  return this->color;
}

int InfinityStone::getBrightness() {
  return this->currentBrightness;
}

void InfinityStone::raiseBrightness(Board &board, int brightness, int d) {
  while ( currentBrightness < brightness ) {
    currentBrightness++;
    this->setBrightness(board, currentBrightness);
    delay(d);
  }
}

void InfinityStone::lowerBrightness(Board &board, int brightness, int d) {
  while ( currentBrightness > brightness ) {
    currentBrightness--;
    this->setBrightness(board, currentBrightness);
    delay(d);
  }
}

void InfinityStone::setBrightness(Board &board, int brightness) {
  float percentage = (brightness * 0.01);
  uint32_t litColor = Adafruit_NeoPixel::Color(
    uint8_t ( color.red * percentage ),
    uint8_t ( color.green * percentage ),
    uint8_t ( color.blue * percentage )
  );
  this->currentBrightness = brightness;

  board.setPixelColor(this->location, litColor);
}