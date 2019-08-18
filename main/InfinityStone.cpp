#include "InfinityStone.h"

InfinityStone::InfinityStone(StoneColor color, int location) {
  this->color = color;
  this->location = location;
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

void InfinityStone::setBrightness(Board &board, int brightness) {
  float percentage = (brightness * 0.01);
  uint32_t litColor = Adafruit_NeoPixel::Color(
    uint8_t ( color.red * percentage ),
    uint8_t ( color.green * percentage ),
    uint8_t ( color.blue * percentage )
  );

  board.setPixelColor(this->location, litColor);
}