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
    InfinityStone(StoneColor, int);
    InfinityStone(const InfinityStone&);
    InfinityStone() { }

    StoneColor getColor();
    int getLocation();
    int getBrightness();

    void setBrightness(Board&, int);
    void raiseBrightness(Board&, int, int);
    void lowerBrightness(Board&, int, int);

  private:
    StoneColor color;
    // The LED's location in the wiring chain.
    int location;
    int currentBrightness;
};

#endif
