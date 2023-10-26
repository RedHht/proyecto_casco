#include "BluetoothA2DPSource.h"
#include "audios.h"
#include "audio.h"

BluetoothA2DPSource a2dp_source;

SoundData *izquierda = new OneChannel8BitSoundData((int8_t*)izquierda__raw, izquierda__raw_len);
SoundData *derecha = new OneChannel8BitSoundData((int8_t*)derecha__raw, derecha__raw_len);
SoundData *adelante = new OneChannel8BitSoundData((int8_t*)adelante__raw, adelante__raw_len);

void initializeaudio() {
    a2dp_source.set_auto_reconnect(true);
    a2dp_source.start("Mi True Wireless EBs Basic_2");
    a2dp_source.set_volume(100);
}

void audioalert(direccionAudio direccion) {
    switch (direccion) {
        case IZQUIERDA:
            a2dp_source.write_data(izquierda);
            break;
        case DERECHA:
            a2dp_source.write_data(derecha);
            break;
        case ADELANTE:
            a2dp_source.write_data(adelante);
            break;
    }
}