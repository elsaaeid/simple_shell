#include "main.h"
/* buffer_handling.c */

/**
 * Function of init_buffer
 *
 * Return: 0 on success
 */

void init_buffer(Buffer* buffer) {
    buffer->length = 0;
    memset(buffer->buffer, 0, BUFFER_SIZE);
}

/**
 * Function to add data to the buffer memory
 *
 * Return: 0 on success
 */
void add_to_buffer(Buffer* buffer, const char* data) {
    int data_length = strlen(data);
    if (buffer->length + data_length < BUFFER_SIZE) {
        strcat(buffer->buffer, data);
        buffer->length += data_length;
    } else {
        printf("Buffer overflow!\n");
    }
}
/**
 * Function to clear the buffer memory
 *
 * Return: 0 on success
 */
void clear_buffer(Buffer* buffer) {
    buffer->length = 0;
    memset(buffer->buffer, 0, BUFFER_SIZE);
}

/**
 * Function to print the contents of the buffer memory
 *
 * Return: 0 on success
 */
void print_buffer(const Buffer* buffer) {
    printf("Buffer contents: %s\n", buffer->buffer);
}
