#ifndef SINUSOIDE_H
#define SINUSOIDE_H

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>
#include <alsa/asoundlib.h>

#define SAMPLE_RATE 44100
#define AMPLITUDE   1.0

short make_sinusoide(int *num_samples, short *buffer);

#endif