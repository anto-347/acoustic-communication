#include "../include/sound.h"
#include "../include/sinusoide.h"
#include "../include/message.h"


#define ENERGY_THRESHOLD 1e15

int main() {
    snd_pcm_t *handle;
    snd_pcm_hw_params_t *params;
    
    int continuer = 1;

    while (continuer) {
        int allocationSize = 2001;
        char input[256];
        char *binaryRepresentation;
        short *buffer;
        
        if (mode_is_send()) {
            create_message(input, sizeof(input));

            while (allocationSize > 2000 || allocationSize <= 0) {
                printf("Nombre de bits à allouer pour le batcher binaire (max: 2000) : ");
                scanf("%d", &allocationSize);
            }
            binaryRepresentation = malloc(allocationSize * sizeof(*binaryRepresentation) + 1);
            if (binaryRepresentation == NULL) {
                printf("Erreur d'allocation de mémoire.\n");
                return 1;
            }

            message_to_binary(binaryRepresentation, input);
            int num_samples = ((strlen(binaryRepresentation) * 0.5) * 0.5) * SAMPLE_RATE;
            buffer = malloc(num_samples * sizeof(*buffer));

            create_sinusoide(binaryRepresentation, num_samples, buffer);
            
            open_device_audio(&handle, 0);
            configure_device(params, handle);
            play_sound(handle, buffer, &num_samples);

            free(binaryRepresentation);
            binaryRepresentation = NULL;

            free(buffer);
            buffer = NULL;

        } else {
            open_device_audio(&handle, 1);
            configure_device(params, handle);

            short buffer[22050];
            char preamble_received[9] = "";
            char message_bits[256 * 8 + 1] = "";
            int header_size = -1;                
            int bits_received = 0;

            typedef enum {
                STATE_WAITING,
                STATE_RECEIVING,
                STATE_DONE
            } ReceiverState;

            ReceiverState state = STATE_WAITING;
            char message[256];
            int bit_count = 0;


            while (state != STATE_DONE) {
                capture_audio(handle, buffer, 22050);

                double freqs[4] = {500.0, 1500.0, 2500.0, 3500.0};
                char *symbols[4] = {"00", "01", "10", "11"};
                double max_energy = 0.0;
                int best = -1;

                for (int i = 0; i < 4; i++) {
                    double energy = goertzel(buffer, 22050, freqs[i], SAMPLE_RATE);
                    if (energy > max_energy) {
                        max_energy = energy;
                        best = i;
                    }
                }

                if (max_energy < ENERGY_THRESHOLD) {
                    printf("Bruit ambiant, on ignore\n");
                    continue;
                }

                switch (state) {
                
                    case STATE_WAITING:
                        strncat(preamble_received, symbols[best], 2);
                
                        if (strlen(preamble_received) > 8) {
                            memmove(preamble_received, preamble_received + 2, 7);
                        }

                        if (strcmp(preamble_received, "00010001") == 0) {
                            printf("Préambule détecté, début de réception...\n");
                            state = STATE_RECEIVING;
                        }
                        break;
                    
                    case STATE_RECEIVING:
                        strncat(message_bits, symbols[best], 2);
                        bits_received += 2;
                    
                        if (header_size == -1 && bits_received >= 8) {
                            char header_bits[9];
                            strncpy(header_bits, message_bits, 8);
                            header_bits[8] = '\0';
                            header_size = (int)strtol(header_bits, NULL, 2);
                            printf("Taille du message annoncée : %d caractères\n", header_size);
                        }
                    
                        if (header_size != -1 && bits_received >= 8 + header_size * 8) {
                            state = STATE_DONE;
                        }
                        break;
                    
                    case STATE_DONE:
                        break;
                }
            }

            printf("Message reçu : ");
            for (int i = 8; i < 8 + header_size * 8; i += 8) {
                char byte_str[9];
                strncpy(byte_str, message_bits + i, 8);
                byte_str[8] = '\0';
                char c = (char)strtol(byte_str, NULL, 2);
                printf("%c", c);
            }
            printf("\n");
        }

        printf("\n****************\nContinuer ? [1/0] ");
        scanf("%d", &continuer);
        while (getchar() != '\n');
    }


    
    return 0;
}