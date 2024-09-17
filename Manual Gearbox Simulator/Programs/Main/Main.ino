#include "gears_bitmaps.h"
#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

const int ERROR = 40;

const int verticalPin = A1;
const int horizontPin = A0;

int verticalValue, horizontValue;
int currentGearIndex;

int getGearIndex(int, int, int = 517, int = 497);

void setup() { u8g2.begin(); }

void loop() {
    verticalValue = map(analogRead(verticalPin), 0, 1023, 1023, 0);
    horizontValue = map(analogRead(horizontPin), 0, 1023, 1023, 0);
    currentGearIndex = getGearIndex(verticalValue, horizontValue);

    u8g2.clearBuffer();
    u8g2.drawXBMP(0, 0, 128, 64, epd_bitmap_gears[currentGearIndex + 1]);
    u8g2.sendBuffer();
}

int getGearIndex(int vert, int horz, int vThreshold, int hThreshold) {
    int gear = 0;

    if (vert > vThreshold + ERROR) {
        if (horz < hThreshold - ERROR)
            gear = -1;
        else if (horz > hThreshold + ERROR)
            gear = 4;
        else
            gear = 2;
    } else if (vert < vThreshold - ERROR) {
        if (horz < hThreshold - ERROR)
            gear = 1;
        else if (horz > hThreshold + ERROR)
            gear = 5;
        else
            gear = 3;
    } else {
        gear = 0;
    }

    return gear;
}
