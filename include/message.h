#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdio.h>
#include <string.h>

int mode_is_send(void);
char create_message(void);
int message_to_binary(char *inputUser);

#endif