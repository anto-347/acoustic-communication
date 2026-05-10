#include "../include/message.h"

int mode_is_send(void)
{
    char mode;
    
    printf("Souhaitez-vous envoyer un message [e] ou en recevoir [r] ? \n>>> ");
    scanf("%c", &mode);

    if (mode == 'e') return 1;
    return 0;
}

void create_message(char *input, size_t size)
{
    while (getchar() != '\n');

    printf("Entrez votre message : ");
    fgets(input, size, stdin);

    input[strcspn(input, "\n")] = '\0';
}

void message_to_binary(char *binaryRepresentation, char *inputUser)
{
    char beginningKey[] = {'0', '1', '0', '1', '0', '1', '0', '1'};
    char head[9];
    int lenInputUser = (int)strlen(inputUser);
    
    dec_to_bin_8(lenInputUser, head);
    printf("%s (bin) => %d (dec)", head, lenInputUser);

    int indexBinaryRepresentation = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
            if (i = 0) binaryRepresentation[indexBinaryRepresentation] = beginningKey[j];
            else binaryRepresentation[indexBinaryRepresentation] = head[j];
            indexBinaryRepresentation++;
        }
    }
}