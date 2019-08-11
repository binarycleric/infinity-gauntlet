#ifndef InfinityStone_H
#define InfinityStone_H

#include <Adafruit_NeoPixel.h>

struct StoneColor {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

class InfinityStone {
  public:
    uint32_t getColor(int brightness);
  
    StoneColor color; 
    // The LED's location in the wiring chain.
    int location;
};

#endif
