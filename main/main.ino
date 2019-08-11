#include <Adafruit_NeoPixel.h>

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

struct StoneColor {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

struct InfinityStone {
  StoneColor color; 
  // The LED's location in the wiring chain.
  int location;
};

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

Adafruit_NeoPixel gauntlet = Adafruit_NeoPixel(PIXEL_COUNT, PIXELCHAIN_PIN, NEO_GRB + NEO_KHZ800);

uint32_t getStoneBrightness(InfinityStone stone, int brightness) {
  float percentage = (brightness * 0.01);
  
  return Adafruit_NeoPixel::Color(
    uint8_t ( stone.color.red * percentage ),
    uint8_t ( stone.color.green * percentage ),
    uint8_t ( stone.color.blue * percentage )
  );
}

InfinityStone getStone(int location) {
  return foundOrder[location];
}

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
    InfinityStone stone = getStone(i);
    uint32_t color = getStoneBrightness(stone, currentPulse());
    gauntlet.setPixelColor(stone.location, color);
  }
  gauntlet.show();
  incrementPulse(); 
}

void blackoutGauntlet() {
  for ( int i = 0; i < 6; i++ ) {
    InfinityStone stone = getStone(i);
    uint32_t color = getStoneBrightness(stone, 0);
    gauntlet.setPixelColor(stone.location, color);
  }  
  gauntlet.show();
}


// Light the stones in the order Thanos found them.
void lightAllStones(int brightness) {
  for ( int i = 0; i < 6; i++ ) {
    InfinityStone stone = getStone(i);
    uint32_t color = getStoneBrightness(stone, brightness);
    gauntlet.setPixelColor(stone.location, color);
  }  
  gauntlet.show();  
}

void lightStone(InfinityStone stone) {
  int levels[] = {
    random(26, 34),
    random(35, 42),
    random(45, 55),
    random(59, 78),
    random(80, 90),
    100,
    random(92, 98),
    random(95, 84),
  }; 

  for ( int j = 0; j < sizeof(levels) / sizeof(int); j++ ) {
    uint32_t color = getStoneBrightness(stone, levels[j]);
    
    gauntlet.setPixelColor(stone.location, color);
    gauntlet.show();
    
    delay(random(85, 115));
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
  
  gauntlet.begin();
  gauntlet.setBrightness(255);

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
