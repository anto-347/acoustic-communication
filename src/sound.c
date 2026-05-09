#include "../include/sound.h"


void open_device_audio(snd_pcm_t **handle)
{
    int err = snd_pcm_open(handle, "default", SND_PCM_STREAM_PLAYBACK, 0);
    if (err < 0) {
        fprintf(stderr, "Erreur ouverture ALSA : %s\n", snd_strerror(err));
        exit(1);
    }
}

void configure_device(snd_pcm_hw_params_t *params, snd_pcm_t *handle)
{
    snd_pcm_hw_params_malloc(&params);
    snd_pcm_hw_params_any(handle, params);
    snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);
    snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_S16_LE);
    snd_pcm_hw_params_set_channels(handle, params, 1);
    unsigned int rate = SAMPLE_RATE;
    snd_pcm_hw_params_set_rate_near(handle, params, &rate, 0);
    snd_pcm_hw_params(handle, params);
    snd_pcm_hw_params_free(params);
}

void play_sound(snd_pcm_t *handle, short *buffer, int *num_samples)
{
    snd_pcm_prepare(handle);
    snd_pcm_writei(handle, buffer, *num_samples);
    snd_pcm_drain(handle);

    snd_pcm_close(handle);
}