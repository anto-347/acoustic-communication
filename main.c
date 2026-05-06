#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>
#include <alsa/asoundlib.h>

#define SAMPLE_RATE 44100
#define DURATION    10
#define FREQUENCY   15000.0
#define AMPLITUDE   1.0

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

    // Ouvrir le device audio
    snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0);

    // Configurer : 44100 Hz, mono, 16 bits signé
    snd_pcm_hw_params_malloc(&params);
    snd_pcm_hw_params_any(handle, params);
    snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);
    snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_S16_LE);
    snd_pcm_hw_params_set_channels(handle, params, 1);
    unsigned int rate = SAMPLE_RATE;
    snd_pcm_hw_params_set_rate_near(handle, params, &rate, 0);
    snd_pcm_hw_params(handle, params);
    snd_pcm_hw_params_free(params);

    // Préparer et jouer
    snd_pcm_prepare(handle);
    snd_pcm_writei(handle, buffer, num_samples);
    snd_pcm_drain(handle);  // attendre la fin de la lecture

    snd_pcm_close(handle);
    
    return 0;
}