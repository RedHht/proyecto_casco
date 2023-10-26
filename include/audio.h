#ifndef GORRA_SONIDO_H
#define GORRA_SONIDO_H

enum direccionAudio {IZQUIERDA, DERECHA, ADELANTE};

void initializeaudio();
void audioalert(direccionAudio direccion);

#endif //GORRA_SONIDO_H