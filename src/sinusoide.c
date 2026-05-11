#include "../include/sinusoide.h"

void create_sinusoide(char *binaryRepresentation, int num_samples, short *buffer)
{
    int frequency;
    int indexBuffer = 0;

    for (int i = 0; i < strlen(binaryRepresentation); i += 2) {
        if (
            binaryRepresentation[i] == '0' &&
            binaryRepresentation[i + 1] == '0'
        ) {
            frequency = 500;
        } else if (
            binaryRepresentation[i] == '0' &&
            binaryRepresentation[i + 1] == '1'
        ) {
            frequency = 1500;
        } else if (
            binaryRepresentation[i] == '1' &&
            binaryRepresentation[i + 1] == '0'
        ) {
            frequency = 2500;
        } else if (
            binaryRepresentation[i] == '1' &&
            binaryRepresentation[i + 1] == '1'
        ) {
            frequency = 3500;
        }


        for (int j = 0; j < 22050; j++) {
            double t = (double)j / SAMPLE_RATE;
            buffer[indexBuffer++] = (short)(AMPLITUDE * 32767.0 * sin(2.0 * M_PI * frequency * t));
        }
    }
}