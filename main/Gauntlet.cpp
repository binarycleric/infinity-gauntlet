#include "Gauntlet.h"
#include "InfinityStone.h"

const int Gauntlet::MIN_BRIGHTNESS = 6;
const int Gauntlet::MAX_BRIGHTNESS = 100;
const int Gauntlet::STONE_COUNT = 6;

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

  for ( int i = 0; i < STONE_COUNT; i++ ) {
    for ( int brightness = MIN_BRIGHTNESS; brightness <= MAX_BRIGHTNESS; brightness++ ) {
      this->foundOrder[i].raiseBrightness(board, brightness, random(11, 25));
    }
  }
}

void Gauntlet::fadeBrightness(Board &board, int brightness) {
  bool keepGoing = false;

  do {
    keepGoing = false;

    for ( int i = 0; i < STONE_COUNT; i++ ) {
      int current = this->foundOrder[i].getBrightness();

      if ( current > brightness ) {
        this->foundOrder[i].lowerBrightness(board, current - 1, 0);
      } else if ( current < brightness ) {
        this->foundOrder[i].raiseBrightness(board, current + 1, 0);
      }

      if ( this->foundOrder[i].getBrightness() != brightness ) {
        keepGoing = (keepGoing || true);
      }
    }
    delay(random(10, 25));
  } while ( keepGoing );
}

// This is a real mess. TODO: Cleanup someday.
void Gauntlet::ripGamora(Board &board) {
  this->fadeBrightness(board, MIN_BRIGHTNESS);
  InfinityStone soulStone = this->foundOrder[3];

  delay(500);
  soulStone.raiseBrightness(board, MAX_BRIGHTNESS, random(11, 25));
  delay(500);
  soulStone.lowerBrightness(board, MIN_BRIGHTNESS, random(11, 25));

  delay(250);

  soulStone.raiseBrightness(board, MAX_BRIGHTNESS, random(6, 15));
  delay(500);
  soulStone.lowerBrightness(board, MIN_BRIGHTNESS, random(6, 15));

  delay(250);

  soulStone.raiseBrightness(board, MAX_BRIGHTNESS, random(2, 10));
  soulStone.lowerBrightness(board, MAX_BRIGHTNESS - 25, random(2, 10));
  delay(250);
  soulStone.raiseBrightness(board, MAX_BRIGHTNESS, random(2, 10));
  soulStone.lowerBrightness(board, MAX_BRIGHTNESS - 25, random(2, 10));
  delay(250);

  soulStone.raiseBrightness(board, MAX_BRIGHTNESS, random(20, 40));
  delay(500);
  soulStone.lowerBrightness(board, MIN_BRIGHTNESS, 10);

  delay(1000);
}

void Gauntlet::pulseStones(Board &board, int delayTime) {
  int startingBrightness = 44;
  this->fadeBrightness(board, startingBrightness);

  for ( int p1 = startingBrightness; p1 <= 100; p1++ ) {
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
  for ( int i = 0; i < STONE_COUNT; i++ ) {
    this->foundOrder[i].setBrightness(board, brightness);
  }
}
