#ifndef SINUSOIDE_H
#define SINUSOIDE_H

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>
#include <string.h>

#define SAMPLE_RATE 44100
#define AMPLITUDE   1.0

void create_sinusoide(char *binaryRepresentation, int num_samples, short *buffer);

#endif