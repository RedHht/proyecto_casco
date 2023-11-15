#include   <Arduino.h>
#include "../lib/sonido/src/audio.h"
#include "../lib/ultrasonido/src/ultrasonido.h"

#define DISTANCE 70

void setup() {
    Serial.begin(115200);
    initializeAudio();
}

void loop() {
    delay(1000);

    float left_distance = getDistance(LEFT_ULTRASOUND),
    right_distance = getDistance(RIGHT_ULTRASOUND),
    front_distance = getDistance(FRONT_ULTRASOUND);

    Serial.println("Izquierda: ");
    Serial.println(left_distance);
    Serial.println("Derecha: ");
    Serial.println(right_distance);
    Serial.println("Adelante: ");
    Serial.println(front_distance);

    if (front_distance <= DISTANCE) {
        audioAlert(FRONT);
    } else if (right_distance <= DISTANCE) {
        audioAlert(RIGHT);
    } else if (left_distance <= DISTANCE) {
        audioAlert(LEFT);
    }
}