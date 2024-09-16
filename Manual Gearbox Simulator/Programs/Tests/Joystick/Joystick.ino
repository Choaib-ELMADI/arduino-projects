const int verticalPin = A1;
const int horizontPin = A0;
int verticalValue, horizontValue;
int currentGear;

int getGearIndex(int, int, int = 512, int = 511);

void setup() { Serial.begin(115200); }

void loop() {
    verticalValue = analogRead(verticalPin);
    horizontValue = map(analogRead(horizontPin), 0, 1023, 1023, 0);
    currentGear = getGearIndex(verticalValue, horizontValue);
    Serial.print("Current gear index: ");
    Serial.println(currentGear);
}

int getGearIndex(int vert, int horz, int vThreshold, int hThreshold) {
    int gear = 0;

    if (vert > vThreshold) {
        if (horz < hThreshold)
            gear = 1;
        else if (horz > hThreshold)
            gear = 5;
        else
            gear = 3;
    } else if (vert < vThreshold) {
        if (horz < hThreshold)
            gear = 2;
        else if (horz > hThreshold)
            gear = -1;
        else
            gear = 4;
    } else {
        gear = 0;
    }

    return gear;
}
