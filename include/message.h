#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdio.h>
#include <string.h>

int mode_is_send(void);
void create_message(char *input, size_t size);
void message_to_binary(int *binaryRepresentation, char *inputUser);

#endif