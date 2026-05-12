#include "../include/utils.h"


void dec_to_bin_8(uint8_t decimal_value, char head[9])
{
    for (int i = 7; i >= 0; i--) {
        head[7 - i] = ((decimal_value >> i) & 1) + '0';
    }

    head[8] = '\0';
}

void dec_to_bin_7(uint8_t decimal_value, char bin[8])
{
    for (int i = 6; i >= 0; i--) {
        bin[6 - i] = ((decimal_value >> i) & 1) + '0';
    }

    bin[7] = '\0';
}

double goertzel(short *buffer, int num_samples, double target_freq, int sample_rate)
{
    double k = (double)num_samples * target_freq / sample_rate;
    double omega = 2.0 * M_PI * k / num_samples;
    double coeff = 2.0 * cos(omega);

    double prev1 = 0.0;
    double prev2 = 0.0;

    for (int i = 0; i < num_samples; i++) {
        double s = (double)buffer[i] + coeff * prev1 - prev2;
        prev2 = prev1;
        prev1 = s;
    }

    return prev2*prev2 + prev1*prev1 - coeff*prev1*prev2;
}