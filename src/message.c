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

    printf("Entrez votre message : ");
    scanf("%c", &buffer);

    return *buffer;
}