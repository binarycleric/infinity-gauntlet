#ifndef Board_H
#define Board_H

#include <Adafruit_NeoPixel.h>

class Board {
  public:
    Board(int, int);

    void setup();
    void setPixelColor(int location, uint32_t color);

  private:
    bool isSetup;
    Adafruit_NeoPixel controller;
};

#endif