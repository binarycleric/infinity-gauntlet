#include "InfinityStone.h"

InfinityStone::InfinityStone(StoneColor color, int location) {
  this->color = color;
  this->location = location;
}

uint32_t InfinityStone::getColor(int brightness = 100) {
  float percentage = (brightness * 0.01);

  return Adafruit_NeoPixel::Color(
    uint8_t ( color.red * percentage ),
    uint8_t ( color.green * percentage ),
    uint8_t ( color.blue * percentage )
  );
}

void InfinityStone::setBrightness(Board &board, int brightness) {
  uint32_t color = getColor(brightness);
  board.setPixelColor(this->location, color);
}