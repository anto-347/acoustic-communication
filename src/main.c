#include "../include/sound.h"

int main() {
    snd_pcm_t *handle;
    snd_pcm_hw_params_t *params;
    int num_samples = SAMPLE_RATE * DURATION;
    short buffer[num_samples];

    // Générer la sinusoïde
    for (int i = 0; i < num_samples; i++) {
        double t = (double)i / SAMPLE_RATE;
        buffer[i] = (short)(AMPLITUDE * 32767.0 * sin(2.0 * M_PI * FREQUENCY * t));
    }

    open_device_audio(&handle);
    configure_device(params, handle);


    // Préparer et jouer
    snd_pcm_prepare(handle);
    snd_pcm_writei(handle, buffer, num_samples);
    snd_pcm_drain(handle);  // attendre la fin de la lecture

    snd_pcm_close(handle);
    
    return 0;
}