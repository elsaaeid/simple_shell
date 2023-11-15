#ifndef MAIN_H
#define MAIN_H

/*---LIBRARIES---*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_NUM_ARGUMENTS 10


/* read_command.c */
void read_command(char* command);

/* execute_builtin_command.c */
void execute_builtin_command(char** arguments);

/* tokenize_input */
void tokenize_input(char* command, char** arguments);

/* execute_command.c */
void execute_command(char** args);

/* is_builtin_command.c */
int is_builtin_command(char* command);
#endif
