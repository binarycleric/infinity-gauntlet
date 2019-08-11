#ifndef Board_H
#define Board_H

#include <Adafruit_NeoPixel.h>

class Board {
  public:
    Board(Adafruit_NeoPixel &controller);
    void setup();
    void setPixelColor(int location, uint32_t color);
    void show();

  private:
    int _pixelPin;
    bool _setup;
    Adafruit_NeoPixel _controller;
};

#endif