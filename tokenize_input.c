//tokenize_input.c
#include "main.h"

/**
 * Function to tokenize the input command
 *
 * Return: 0 on success
 */
char** tokenize_input(const char* input) {
    int buffer_size = BUFFER_SIZE;
    int position = 0;
    char** tokens = malloc(buffer_size * sizeof(char*));
    char* token;
    
    if (!tokens) {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }
    
    token = strtok((char*)input, TOKEN_DELIMITERS);
    while (token != NULL) {
        tokens[position] = token;
        position++;
        
        if (position >= buffer_size) {
            buffer_size += BUFFER_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        
        token = strtok(NULL, TOKEN_DELIMITERS);
    }
    tokens[position] = NULL;
    return tokens;
}
