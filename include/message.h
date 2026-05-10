#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdio.h>
#include <string.h>

#include "../include/utils.h"

int mode_is_send(void);
void create_message(char *input, size_t size);
void message_to_binary(char *binaryRepresentation, char *inputUser);

#endif