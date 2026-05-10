#include "../include/utils.h"


void dec_to_bin_8(uint8_t decimal_value, char head[9])
{
    for (int i = 7; i >= 0; i--) {
        head[7 - i] = ((decimal_value >> i) & 1) + '0';
    }

    head[8] = '\0';
}