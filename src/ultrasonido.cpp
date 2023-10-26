#include <Arduino.h>
#include "ultrasonido.h"

#define SOUND_SPEED 340
#define TRIG_PULSE_DURATION_US 10

long ultrason_duration;
float distance_cm;

int trig_pin;
int echo_pin;

void setuppins() {
    pinMode(trig_pin, OUTPUT); // We configure the trig as output
    pinMode(echo_pin, INPUT); // We configure the echo as input
}

float getdistance(ultrasonidos ultrasonido) {
    setpins(ultrasonido);
    setuppins();
    // Set up the signal
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);
    // Create a 10 µs impulse
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(TRIG_PULSE_DURATION_US);
    digitalWrite(trig_pin, LOW);

    // Return the wave propagation time (in µs)
    ultrason_duration = pulseIn(echo_pin, HIGH);

//distance calculation
    distance_cm = ultrason_duration * SOUND_SPEED/2 * 0.0001;

    return distance_cm;
}

void setpins(ultrasonidos ultrasonido) {
    switch (ultrasonido) {
        case ULTRASONIDO_IZQUIERDO:
            trig_pin = 16;
            echo_pin = 17;
            break;
        case ULTRASONIDO_DERECHO:
            trig_pin = 5;
            echo_pin = 18;
            break;
        case ULTRASONIDO_DELANTERO:
            trig_pin = 32;
            echo_pin = 33;
            break;
    }
}