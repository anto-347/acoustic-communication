#include "../include/sound.h"
#include "../include/sinusoide.h"
#include "../include/message.h"


int main() {
    snd_pcm_t *handle;
    snd_pcm_hw_params_t *params;
    char input[256];
    int binaryRepresentation;

    int continuer = 1;

    while (continuer) {
        if (mode_is_send()) {
            create_message(input, sizeof(input));
            message_to_binary(binaryRepresentation, input);
        }
        continuer = 0;
    }


    // int num_samples = SAMPLE_RATE * DURATION;
    // short buffer[num_samples];

    // // Générer la sinusoïde
    // for (int i = 0; i < num_samples; i++) {
    //     double t = (double)i / SAMPLE_RATE;
    //     buffer[i] = (short)(AMPLITUDE * 32767.0 * sin(2.0 * M_PI * FREQUENCY * t));
    // }

    // open_device_audio(&handle);
    // configure_device(params, handle);

    // play_sound(handle, buffer, &num_samples);
    
    return 0;
}