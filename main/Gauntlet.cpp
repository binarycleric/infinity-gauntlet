#include "Gauntlet.h"
#include "InfinityStone.h"

const int Gauntlet::MIN_BRIGHTNESS = 6;

Gauntlet::Gauntlet() {
  // power stone
  this->foundOrder[0] = InfinityStone(StoneColor { 255,   0, 255 }, 1);
  // space stone
  this->foundOrder[1] = InfinityStone(StoneColor {   0,   0, 255 }, 2);
  // reality stone
  this->foundOrder[2] = InfinityStone(StoneColor { 255,   0,   0 }, 3);
  // soul stone
  this->foundOrder[3] = InfinityStone(StoneColor { 255, 255,   0 }, 4);
  // time stone
  this->foundOrder[4] = InfinityStone(StoneColor {   0, 255,   0 }, 0);
  // mind stone
  this->foundOrder[5] = InfinityStone(StoneColor { 255, 255,   0 }, 5);
}

void Gauntlet::lightStonesInOrder(Board &board) {
  this->lightStones(board, MIN_BRIGHTNESS);
  delay(1000);

  for ( int i = 0; i < 6; i++ ) {
    for ( int brightness = MIN_BRIGHTNESS; brightness <= 100; brightness++ ) {
      this->foundOrder[i].setBrightness(board, brightness);
      delay(random(11, 25));
    }
  }
}

void Gauntlet::pulseStones(Board &board, int delayTime) {
  for ( int p1 = 44; p1 <= 100; p1++ ) {
    this->lightStones(board, p1);
    delay(delayTime);
  }

  for ( int p2 = 100; p2 > 85; p2-- ) {
    this->lightStones(board, p2);
    delay(delayTime);
  }

  for ( int p2 = 85; p2 < 100; p2++ ) {
    this->lightStones(board, p2);
    delay(delayTime);
  }

  for ( int p2 = 100; p2 > 85; p2-- ) {
    this->lightStones(board, p2);
    delay(delayTime);
  }

  for ( int p3 = 85; p3 > 44; p3-- ) {
    this->lightStones(board, p3);
    delay(delayTime);
  }
}

void Gauntlet::lightStones(Board &board, int brightness) {
  for ( int i = 0; i < 6; i++ ) {
    this->foundOrder[i].setBrightness(board, brightness);
  }
}