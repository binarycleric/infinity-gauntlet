#include <Adafruit_NeoPixel.h>
#include "InfinityStone.h"
#include "Board.h"

#define PIXELCHAIN_PIN 6
#define PIXEL_COUNT 6

int brightness = 50;
int minimumBrightness = 10;

InfinityStone foundOrder[] = {
  // Power Stone.
  InfinityStone(StoneColor { 255,   0, 255 }, 1),
  // Space Stone.
  InfinityStone(StoneColor {   0,   0, 255 }, 2),
  // Reality Stone.
  InfinityStone(StoneColor { 255,   0,   0 }, 3),
  // Soul Stone.
  InfinityStone(StoneColor { 255, 255,   0 }, 4),
  // Time Stone.
  InfinityStone(StoneColor {   0, 255,   0 }, 0),
  // Mind Stone.
  InfinityStone(StoneColor { 255, 255,   0 }, 5)
};

Adafruit_NeoPixel controller = Adafruit_NeoPixel(PIXEL_COUNT, PIXELCHAIN_PIN, NEO_GRB + NEO_KHZ800);
Board board = Board(controller);

void blackoutGauntlet() {
  for ( int i = 0; i < 6; i++ ) {
    InfinityStone stone = foundOrder[i];
    stone.setBrightness(board, minimumBrightness);
  }
}

// Light the stones in the order Thanos found them.
void lightAllStones(int brightness) {
  for ( int i = 0; i < 6; i++ ) {
    InfinityStone stone = foundOrder[i];
    stone.setBrightness(board, brightness);
  }
}

void lightStone(InfinityStone stone) {
  for ( int j = minimumBrightness; j <= 100; j++ ) {
    stone.setBrightness(board, j);
    delay(random(11, 25));
  }
}

void lightStonesInOrder() {
  blackoutGauntlet();
  delay(1000);

  for ( int i = 0; i < 6; i++ ) {
    lightStone(foundOrder[i]);
  }
}

void hardPulseStones(int delayTime) {
  for ( int p1 = 44; p1 <= 100; p1++ ) {
    lightAllStones(p1);
    delay(delayTime);
  }

  for ( int p2 = 100; p2 > 85; p2-- ) {
    lightAllStones(p2);
    delay(delayTime);
  }

  for ( int p2 = 85; p2 < 100; p2++ ) {
    lightAllStones(p2);
    delay(delayTime);
  }

  for ( int p2 = 100; p2 > 85; p2-- ) {
    lightAllStones(p2);
    delay(delayTime);
  }

  for ( int p3 = 85; p3 > 44; p3-- ) {
    lightAllStones(p3);
    delay(delayTime);
  }
}

void setup() {
  randomSeed(analogRead(0));

  board.setup();

  lightStonesInOrder();
  hardPulseStones(random(20, 40));
  hardPulseStones(random(30, 50));
}

void loop() {
  // Stan Lee's age and Earth 616 (MCU)
  if (( random(95, 10000) <= 616 )) {
    lightStonesInOrder();
  }

  hardPulseStones(random(2, 25));
  delay(random(125, 425));
}
