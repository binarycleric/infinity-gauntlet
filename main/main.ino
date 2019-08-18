#include "Gauntlet.h"
#include "Board.h"

#define PIXELCHAIN_PIN 6
#define PIXEL_COUNT 6

Board board = Board(PIXEL_COUNT, PIXELCHAIN_PIN);
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
  if ( random(95, 10000) <= 616 ) {
    gauntlet.lightStonesInOrder(board);
  }

  if ( random(1, 10000) >= 9850 ) {
    gauntlet.ripGamora(board);
  }

  gauntlet.pulseStones(board, random(2, 25));
  delay(random(125, 425));
}
