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

void message_to_binary(int *binaryRepresentation, char *inputUser)
{
    
}