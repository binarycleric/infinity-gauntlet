#include <Adafruit_NeoPixel.h>
#include "InfinityStone.h"

#define PIXELCHAIN_PIN 6
#define PIXEL_COUNT 6

int brightness = 50;
int pulseLocation = 0;

// Levles while all the stones are pulsing. Think when Thanos
// finally collected them all.
int pulseLevels[] = {
  30, 
  35,
  42, 
  45,
  55, 
  60, 
  80,
  85,
  90, 
  100, 
  95, 
  90, 
  85,
  82,
  80,
  60,
  55,
  50,
  43,
};

int pulseLength = sizeof(pulseLevels) / sizeof(int);

InfinityStone timeStone    = { StoneColor {   0, 255,   0 }, 0 };
InfinityStone powerStone   = { StoneColor { 255,   0, 255 }, 1 };
InfinityStone spaceStone   = { StoneColor {   0,   0, 255 }, 2 };
InfinityStone realityStone = { StoneColor { 255,   0,   0 }, 3 };
InfinityStone soulStone    = { StoneColor { 255, 255,   0 }, 4 };
InfinityStone mindStone    = { StoneColor { 255, 255,   0 }, 5 };

InfinityStone foundOrder[] = {
  powerStone,
  spaceStone,
  realityStone,
  soulStone,
  timeStone,
  mindStone,
};

Adafruit_NeoPixel controller = Adafruit_NeoPixel(PIXEL_COUNT, PIXELCHAIN_PIN, NEO_GRB + NEO_KHZ800);

int currentPulse() {
  return pulseLevels[pulseLocation];
}

int resetPulse() {
  pulseLocation = 0;
}

int incrementPulse() {
  if ( pulseLocation >= pulseLength ) {
    resetPulse();
  } else {
    pulseLocation++;
  } 
}

void updateStones() {
  for ( int i = 0; i < 6; i++ ) {
    InfinityStone stone = foundOrder[i];
    uint32_t color = stone.getColor(currentPulse());
    controller.setPixelColor(stone.location, color);
  }
  controller.show();
  incrementPulse(); 
}

void blackoutGauntlet() {
  for ( int i = 0; i < 6; i++ ) {
    InfinityStone stone = foundOrder[i];
    uint32_t color = stone.getColor(0);    
    controller.setPixelColor(stone.location, color);
  }  
  controller.show();
}


// Light the stones in the order Thanos found them.
void lightAllStones(int brightness) {
  for ( int i = 0; i < 6; i++ ) {
    InfinityStone stone = foundOrder[i];
    uint32_t color = stone.getColor(brightness);
    controller.setPixelColor(stone.location, color);
  }  
  controller.show();  
}

void lightStone(InfinityStone stone) {
  for ( int j = 1; j <= 100; j++ ) {
    uint32_t color = stone.getColor(j);
    controller.setPixelColor(stone.location, color);
    controller.show();
    
    delay(random(8, 20));    
  }
}

void lightStonesInOrder() { 
  blackoutGauntlet();
  delay(1000);

  for ( int i = 0; i < 6; i++ ) {
    lightStone(foundOrder[i]);
  }
}

void hardPulseStones(int pulseTimes) {
  for ( int j = 0; j < pulseTimes; j++ ) {
    for ( int k = 0; k < sizeof(pulseLevels) / sizeof(int); k++ ) {
      lightAllStones(pulseLevels[k]);
      delay(150);
    }
  } 
}

void setup() { 
  randomSeed(analogRead(0));
  
  controller.begin();
  controller.setBrightness(255);  

  lightStonesInOrder();
  hardPulseStones(2);
}

void loop() {
  // Stan Lee's age and Earth 616 (MCU)
  if (( random(95, 150000) <= 616 )) {
    lightStonesInOrder();
    hardPulseStones(random(0, 3));    
    resetPulse();
  }
  
  updateStones();
  delay(random(125, 425));
}
