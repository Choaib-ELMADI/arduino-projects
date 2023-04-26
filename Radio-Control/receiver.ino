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

void setup() {
  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
    if (radio.available()) {
      radio.read(&data, sizeof(DATA));
      Serial.print("data: xLeft = ");
      Serial.print(data.xL);
      Serial.print(" yLeft = ");
      Serial.print(data.yL);
      Serial.print(" xRight = ");
      Serial.print(data.xR);
      Serial.print(" yRight = ");
      Serial.println(data.yR);
    } else {
      Serial.println("Nothing ..");
    }
}
