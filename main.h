#ifndef MAIN_H
#define MAIN_H

/*---LIBRARIES---*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

/* read_line.c */
char* read_line();

/* cd_dir.c */
void cd_dir(char** args);

/* free_tokens.c */
void free_tokens(char** tokens);

/* tokenize_input.c */
char** tokenize_input(char* line);

/* execute_command.c */
void execute_command(char** args);

/* exit_shell.c */
void exit_shell();
#endif
