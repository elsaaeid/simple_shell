#ifndef MAIN_H
#define MAIN_H

/*---LIBRARIES---*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"

/* Structure to hold the buffer memory */
typedef struct {
    char buffer[BUFFER_SIZE];
    int length;
} Buffer;


/* buffer_handling.c */
void init_buffer(Buffer* buffer);
void add_to_buffer(Buffer* buffer, const char* data);
void clear_buffer(Buffer* buffer);
void print_buffer(const Buffer* buffer);

/* execute_command.c */
int execute_command(char** args);

/* handle_builtin_commands.c */
int handle_builtin_commands(char** args);

/* read_input.c */
void read_input(Buffer* buffer);

/* tokenize_input.c */
char** tokenize_input(const char* input);
#endif
