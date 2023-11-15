/* read_command.c */
#include "main.h"

/**
 * read_command is function to read a line of command from the user
 * @command
 * Return: read line
 */
void read_command(char* command) {
    printf("Enter a command: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = '\0';
}
