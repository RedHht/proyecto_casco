#include <string>
#include "BluetoothA2DPSource.h"
#include "audios.h"
#include "audio.h"

BluetoothA2DPSource a2dp_source;

SoundData *left = new OneChannel8BitSoundData((int8_t*)izquierda__raw, (int32_t) izquierda__raw_len);
SoundData *right = new OneChannel8BitSoundData((int8_t*)derecha__raw, (int32_t) derecha__raw_len);
SoundData *front = new OneChannel8BitSoundData((int8_t*)adelante__raw, (int32_t) adelante__raw_len);

void initializeAudio(char* device_name) {
    a2dp_source.set_auto_reconnect(true);
    a2dp_source.start(device_name);
    a2dp_source.set_volume(100);
}

void audioAlert(AudioDirection direction) {
    switch (direction) {
        case LEFT:
            a2dp_source.write_data(left);
            break;
        case RIGHT:
            a2dp_source.write_data(right);
            break;
        case FRONT:
            a2dp_source.write_data(front);
            break;
    }
}