#include <Servo.h>
Servo panelServo;
int ServoPin = 10;

int LDRPin_1 = A1;
int LDRPin_2 = A2;

int errorBegin = -10;
int errorEnd = 10;


void setup() {
  Serial.begin(9600);

  panelServo.attach(ServoPin);
  panelServo.write(100);
  
  pinMode(LDRPin_1, INPUT);
  pinMode(LDRPin_2, INPUT);

  delay(1000);
}

void loop() {
  int LDRValue_1 = analogRead(LDRPin_1);
  int LDRValue_2 = analogRead(LDRPin_2);
  int Diff = LDRValue_1 - LDRValue_2;
  int angle;

  if (Diff <= errorBegin) {
    panelServo.attach(ServoPin);
    angle = map(abs(Diff), abs(errorBegin), 900, 100, 180);
    panelServo.write(angle);
  } else if (Diff >= errorEnd) {
    panelServo.attach(ServoPin);
    angle = map(Diff, errorEnd, 900, 100, 20);
    panelServo.write(angle);
  } else {
    angle = 100;
    panelServo.write(angle);
    panelServo.detach();
  }
  
}
