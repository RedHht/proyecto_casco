#include <Arduino.h>
#include "audio.h"
#include "ultrasonido.h"

void setup() {
    Serial.begin(115200);
    initializeaudio();
}

void loop() {
    delay(500);

    float distanciaizquierda = getdistance(ULTRASONIDO_IZQUIERDO),
    distanciaderecha = getdistance(ULTRASONIDO_DERECHO),
    distanciadelante = getdistance(ULTRASONIDO_DELANTERO);

    if (distanciaizquierda <= 100) {
        audioalert(IZQUIERDA);
    } else if (distanciaderecha <= 100) {
        audioalert(DERECHA);
    } else if (distanciadelante <= 100) {
        audioalert(ADELANTE);
    }
}