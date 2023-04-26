#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(7, 8);
const byte address[6] = "ABCDE";

typedef struct {
  int xL;
  int yL;
  int xR;
  int yR;
} DATA;
DATA data;

int xLeft  = A0;
int yLeft  = A1;
int xRight = A2;
int yRight = A3;

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  int xLeftValue  = analogRead(xLeft);
  int yLeftValue  = analogRead(yLeft);
  int xRightValue = analogRead(xRight);
  int yRightValue = analogRead(yRight);

  data.xL = xLeftValue;
  data.yL = yLeftValue;
  data.xR = xRightValue;
  data.yR = yRightValue;

  radio.write(&data, sizeof(DATA));
}
