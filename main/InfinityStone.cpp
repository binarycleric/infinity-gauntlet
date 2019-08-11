#include "InfinityStone.h"

uint32_t InfinityStone::getColor(int brightness = 100) {
  float percentage = (brightness * 0.01);
  
  return Adafruit_NeoPixel::Color(
    uint8_t ( color.red * percentage ),
    uint8_t ( color.green * percentage ),
    uint8_t ( color.blue * percentage )
  );
}
