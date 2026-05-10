#include "../include/sound.h"
#include "../include/sinusoide.h"
#include "../include/message.h"


int main() {
    snd_pcm_t *handle;
    snd_pcm_hw_params_t *params;
    
    int continuer = 1;

    while (continuer) {
        int allocationSize = 1793;
        char input[256];
        char *binaryRepresentation;
        
        if (mode_is_send()) {
            create_message(input, sizeof(input));

            while (allocationSize > 1792 || allocationSize <= 0) {
                printf("Nombre de bits à allouer pour le batcher binaire (max: 1792) : ");
                scanf("%d", &allocationSize);
            }
            binaryRepresentation = malloc(allocationSize * sizeof(*binaryRepresentation));
            if (binaryRepresentation == NULL) {
                printf("Erreur d'allocation de mémoire.\n");
                return 1;
            }

            message_to_binary(binaryRepresentation, input);

            printf("%s", binaryRepresentation);
        }

        free(binaryRepresentation);
        binaryRepresentation = NULL;
        continuer = 0;
    }


    // int num_samples = SAMPLE_RATE * DURATION;
    // short buffer[num_samples];

    // // Générer la sinusoïde
    // for (int i = 0; i < num_samples; i++) {
    //     double t = (double)i / SAMPLE_RATE;
    //     buffer[i] = (short)(AMPLITUDE * 32767.0 * sin(2.0 * M_PI * FREQUENCY * t));
    // }

    // open_device_audio(&handle);
    // configure_device(params, handle);

    // play_sound(handle, buffer, &num_samples);
    
    return 0;
}