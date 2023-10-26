#include <Arduino.h>
#include "../lib/sonido/src/audio.h"
#include "../lib/ultrasonido/src/ultrasonido.h"

void setup() {
    Serial.begin(115200);
    initializeAudio((char*) "Mi True Wireless EBs Basic_2");
}

void loop() {
    delay(500);

    float left_distance = getDistance(LEFT_ULTRASOUND),
    right_distance = getDistance(RIGHT_ULTRASOUND),
    front_distance = getDistance(FRONT_ULTRASOUND);

    if (front_distance <= 100) {
        audioAlert(FRONT);
    } else if (right_distance <= 100) {
        audioAlert(RIGHT);
    } else if (left_distance <= 100) {
        audioAlert(LEFT);
    }
}