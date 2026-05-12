#ifndef SOUND_MAC_H
#define SOUND_MAC_H

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>
#include <portaudio.h>
#include <stdlib.h>

#define SAMPLE_RATE 44100
#define AMPLITUDE   1.0

void open_device_audio_mac(PaStream **handle, int mode);
void play_sound_mac(PaStream *handle, short *buffer, int *num_samples);
void capture_audio_mac(PaStream *handle, short *buffer, int num_samples);

#endif