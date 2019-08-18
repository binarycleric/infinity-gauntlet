#ifndef InfinityStone_H
#define InfinityStone_H

#include <Adafruit_NeoPixel.h>
#include "Board.h"

struct StoneColor {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

class InfinityStone {
  public:
    InfinityStone(StoneColor color, int location);
    InfinityStone(const InfinityStone&);
    InfinityStone() { }

    StoneColor getColor();
    int getLocation();

    void setBrightness(Board &board, int brightness);

  private:
    StoneColor color;
    // The LED's location in the wiring chain.
    int location;
};

#endif
