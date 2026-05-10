#include "../include/message.h"

int mode_is_send(void)
{
    char mode;
    
    printf("Souhaitez-vous envoyer un message [e] ou en recevoir [r] ? \n>>> ");
    scanf("%c", &mode);

    if (mode == 'e') return 1;
    return 0;
}

char create_message(void)
{
    char buffer[256];
    while (getchar() != '\n');

    printf("Entrez votre message : ");
    fgets(buffer, 256, stdin);

    buffer[strcspn(buffer, "\n")] = '\0';

    return *buffer;
}

int message_to_binary(char *inputUser)
{

}