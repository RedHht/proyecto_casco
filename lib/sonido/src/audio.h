#ifndef GORRA_SONIDO_H
#define GORRA_SONIDO_H

enum AudioDirection {LEFT, RIGHT, FRONT};

void initializeAudio();
void audioAlert(AudioDirection direction);

#endif //GORRA_SONIDO_H