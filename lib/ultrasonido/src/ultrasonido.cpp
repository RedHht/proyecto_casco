#include <Arduino.h>
#include "ultrasonido.h"

#define SOUND_SPEED 340
#define TRIG_PULSE_DURATION_US 10

float ultrasound_duration;
float distance_cm;

int trig_pin;
int echo_pin;

void configurePins() {
    pinMode(trig_pin, OUTPUT); // We configure the trig as output
    pinMode(echo_pin, INPUT); // We configure the echo as input
}

float getDistance(UltraSounds ultra_sound) {
    setPins(ultra_sound);
    configurePins();
    // Set up the signal
        digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);
    // Create a 10 µs impulse
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(TRIG_PULSE_DURATION_US);
    digitalWrite(trig_pin, LOW);

    // Return the wave propagation time (in µs)
    ultrasound_duration = (float) pulseIn(echo_pin, HIGH);

    //distance calculation
    distance_cm = (float) (ultrasound_duration * SOUND_SPEED / 2 * 0.0001);

    return distance_cm;
}

void setPins(UltraSounds ultra_sound) {
    switch (ultra_sound) {
        case LEFT_ULTRASOUND:
            trig_pin = 16;
            echo_pin = 17;
            break;
        case RIGHT_ULTRASOUND:
            trig_pin = 5;
            echo_pin = 18;
            break;
        case FRONT_ULTRASOUND:
            trig_pin = 32;
            echo_pin = 33;
            break;
    }
}