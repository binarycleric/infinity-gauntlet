#include <Adafruit_NeoPixel.h>
#include "InfinityStone.h"

#define PIXELCHAIN_PIN 6
#define PIXEL_COUNT 6

int brightness = 50;

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

void hardPulseStones(int delayTime=random(10, 25)) {
  // int delayTime = 15;
  
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
  
  controller.begin();
  controller.setBrightness(255);  

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
