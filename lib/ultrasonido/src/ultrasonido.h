//
// Created by Redhht on 25/10/2023.
//

#ifndef GORRA_ULTRASONIDO_H
#define GORRA_ULTRASONIDO_H

enum UltraSounds {
    LEFT_ULTRASOUND,
    RIGHT_ULTRASOUND,
    FRONT_ULTRASOUND
};

void setPins(UltraSounds ultra_sound);
void configurePins();
float getDistance(UltraSounds ultra_sound);

#endif //GORRA_ULTRASONIDO_H
