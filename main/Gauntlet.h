#ifndef Gauntlet_H
#define Gauntlet_H

#include "InfinityStone.h"
#include "Board.h"

class Gauntlet {
  public:
    Gauntlet();

    void lightStones(Board&, int);
    void lightStonesInOrder(Board&);
    void ripGamora(Board&);
    void pulseStones(Board&, int);
    void fadeBrightness(Board&, int);

    static const int MIN_BRIGHTNESS;
    static const int MAX_BRIGHTNESS;

  private:
    InfinityStone foundOrder[6];
};

#endif