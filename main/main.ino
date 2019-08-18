#include <Adafruit_NeoPixel.h>
#include "InfinityStone.h"
#include "Gauntlet.h"
#include "Board.h"

#define PIXELCHAIN_PIN 6
#define PIXEL_COUNT 6

Adafruit_NeoPixel controller = Adafruit_NeoPixel(PIXEL_COUNT, PIXELCHAIN_PIN, NEO_GRB + NEO_KHZ800);
Board board = Board(controller);
Gauntlet gauntlet = Gauntlet();

void setup() {
  randomSeed(analogRead(0));

  board.setup();

  gauntlet.lightStonesInOrder(board);
  gauntlet.pulseStones(board, random(20, 40));
  gauntlet.pulseStones(board, random(30, 50));
}

void loop() {
  // Stan Lee's age and Earth 616 (MCU)
  if (( random(95, 10000) <= 616 )) {
    gauntlet.lightStonesInOrder(board);
  }

  gauntlet.pulseStones(board, random(2, 25));
  delay(random(125, 425));
}
