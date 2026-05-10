#ifndef SOUND_H
#define SOUND_H

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>
#include <alsa/asoundlib.h>

#define SAMPLE_RATE 44100
#define AMPLITUDE   1.0

void configure_device(snd_pcm_hw_params_t *params, snd_pcm_t *handle);
void open_device_audio(snd_pcm_t **handle, int mode);
void play_sound(snd_pcm_t *handle, short *buffer, int *num_samples);

void capture_audio(snd_pcm_t *handle, short *buffer, int num_samples);
double goertzel(short *buffer, int num_samples, double target_freq, int sample_rate);

#endif