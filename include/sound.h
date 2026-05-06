#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>
#include <alsa/asoundlib.h>

#define SAMPLE_RATE 44100
#define DURATION    1
#define FREQUENCY   1000.0
#define AMPLITUDE   1.0

void configure_device(snd_pcm_hw_params_t *params, snd_pcm_t *handle);
void open_device_audio(snd_pcm_t **handle);