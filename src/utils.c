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