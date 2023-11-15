/* read_input.c */
#include "main.h"

/**
 * Function to read a line of input from the user
 *
 * Return: 0 on success
 */
void read_input(Buffer* buffer) {
    char input[BUFFER_SIZE];
    fgets(input, BUFFER_SIZE, stdin);
    add_to_buffer(buffer, input);
}
