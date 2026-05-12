#ifndef UTILS_H
#define UTILS_H

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>
#include <stdint.h>

void dec_to_bin_8(uint8_t decimal_value, char head[9]);
void dec_to_bin_7(uint8_t decimal_value, char bin[8]);
double goertzel(short *buffer, int num_samples, double target_freq, int sample_rate);


#endif