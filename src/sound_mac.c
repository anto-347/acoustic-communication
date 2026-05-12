#include "../include/sound_mac.h"

void open_device_audio_mac(PaStream **handle, int mode)
{
    PaError err;
    Pa_Initialize();

    if (mode == 0) {
        // Playback : 0 entrée, 1 sortie
        err = Pa_OpenDefaultStream(handle, 0, 1, paInt16, SAMPLE_RATE, 256, NULL, NULL);
    } else {
        // Capture : 1 entrée, 0 sortie
        err = Pa_OpenDefaultStream(handle, 1, 0, paInt16, SAMPLE_RATE, 256, NULL, NULL);
    }

    if (err != paNoError) {
        fprintf(stderr, "Erreur ouverture PortAudio : %s\n", Pa_GetErrorText(err));
        exit(1);
    }

    Pa_StartStream(*handle);
}

void play_sound_mac(PaStream *handle, short *buffer, int *num_samples)
{
    PaError err = Pa_WriteStream(handle, buffer, *num_samples);
    if (err != paNoError) {
        fprintf(stderr, "Erreur lecture : %s\n", Pa_GetErrorText(err));
    }

    Pa_StopStream(handle);
    Pa_CloseStream(handle);
    Pa_Terminate();
}

void capture_audio_mac(PaStream *handle, short *buffer, int num_samples)
{
    PaError err = Pa_ReadStream(handle, buffer, num_samples);
    if (err != paNoError) {
        fprintf(stderr, "Erreur capture : %s\n", Pa_GetErrorText(err));
    }
}