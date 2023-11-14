//main.c
#include "main.h"

/**
 * Function of entry point
 *
 * Return: 0 on success
 */
int main() {
    Buffer buffer;
    char** args;
    int status;
    
    init_buffer(&buffer);
    
    do {
        printf("shell> ");
        read_input(&buffer);
        args = tokenize_input(buffer.buffer);
        status = handle_builtin_commands(args);
        
        if (status) {
            status = execute_command(args);
        }
        
        clear_buffer(&buffer);
        free(args);
    } while (status);
    
    return 0;
}
