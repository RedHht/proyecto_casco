//
// Created by Redhht on 25/10/2023.
//

#ifndef GORRA_ULTRASONIDO_H
#define GORRA_ULTRASONIDO_H

enum ultrasonidos {
    ULTRASONIDO_IZQUIERDO,
    ULTRASONIDO_DERECHO,
    ULTRASONIDO_DELANTERO
};

void setpins(ultrasonidos ultrasonido);
void setuppins();
float getdistance(ultrasonidos ultrasonido);

#endif //GORRA_ULTRASONIDO_H
