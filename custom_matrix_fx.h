#ifndef CUSTOM_MATRIX_FX_H
#define CUSTOM_MATRIX_FX_H

#include <Adafruit_NeoPixel.h>
#include <math.h>


#define LED_PIN     27
#define NUM_LEDS    72
#define LAST_VISIBLE_LED 71
#define MATRIX_WIDTH 9
#define MATRIX_HEIGHT 8

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_RGB + NEO_KHZ800);

uint8_t XY(uint8_t x, uint8_t y) {
  if (x >= MATRIX_WIDTH || y >= MATRIX_HEIGHT) return LAST_VISIBLE_LED + 1;

  const uint8_t XYTable[] = {
   23,  24,  25,  26,  27,  28,  29,   0,   1,
     4,   3,   2,  35,  34,  33,  32,  31,  30,
     5,   6,   7,  36,  37,  38,  39,  40,  41,
    10,   9,   8,  47,  46,  45,  44,  43,  42,
    48,  11,  49,  50,  51,  52,  53,  54,  55,
    13,  62,  12,  61,  60,  59,  58,  57,  56,
    63,  64,  65,  14,  15,  16,  17,  18,  19,
    71,  22,  70,  21,  69,  68,  67,  66,  20
  };

  return XYTable[y * MATRIX_WIDTH + x];
}

void initMatrixFX() {
  strip.begin();
  strip.setBrightness(100);  // Adjust brightness here
  strip.show();
}

void shimmerWaveFX(uint8_t frame) {
  for (uint8_t y = 0; y < MATRIX_HEIGHT; y++) {
    for (uint8_t x = 0; x < MATRIX_WIDTH; x++) {
      uint8_t i = XY(x, y);
      if (i > LAST_VISIBLE_LED) continue;

      int dx = x - 4;
      int dy = y - 3;
      float dist = sqrt(dx * dx + dy * dy);
      float waveRaw = sinf((frame - (dist * 30)) * 0.05); // scale for smoothness
      uint8_t wave = (waveRaw + 1.0) * 127.5;             // convert from [-1,1] to [0,255]

      // Color blend
      uint8_t emeraldR = 0, emeraldG = 255, emeraldB = 120;
      uint8_t purpleR = 160, purpleG = 0, purpleB = 255;
      float mix = ((x * y * 7) % 255) / 255.0;

      uint8_t r = emeraldR + mix * (purpleR - emeraldR);
      uint8_t g = emeraldG + mix * (purpleG - emeraldG);
      uint8_t b = emeraldB + mix * (purpleB - emeraldB);

      // Scale by wave
      r = (r * wave) / 255;
      g = (g * wave) / 255;
      b = (b * wave) / 255;

      strip.setPixelColor(i, strip.Color(r, g, b));
    }
  }
  strip.show();
}

void burstFromCenterFX(uint8_t speed, uint32_t color, uint8_t trail, uint8_t centerX, uint8_t centerY) {
  static uint8_t burstFrame = 0;

  for (uint8_t y = 0; y < MATRIX_HEIGHT; y++) {
    for (uint8_t x = 0; x < MATRIX_WIDTH; x++) {
      uint8_t i = XY(x, y);
      if (i > LAST_VISIBLE_LED) continue;

      int dx = x - centerX;
      int dy = y - centerY;
      float dist = sqrt(dx * dx + dy * dy);

      uint8_t wave = constrain(255 - abs(burstFrame - (uint8_t)(dist * 30)), 0, 255);

      uint8_t r = ((color >> 16) & 0xFF) * wave * trail / (255 * 255);
      uint8_t g = ((color >> 8) & 0xFF) * wave * trail / (255 * 255);
      uint8_t b = (color & 0xFF) * wave * trail / (255 * 255);

      strip.setPixelColor(i, strip.Color(r, g, b));
    }
  }

  strip.show();
  burstFrame += speed;
  if (burstFrame > 255) burstFrame = 0;
}



#endif
