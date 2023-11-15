/* execute_command.c */
#include "main.h"

/**
 * execute_command is function to execute a command
 * @args
 * Return: 0 or 1
 */
void execute_command(char** args) {
    pid_t pid = fork();
    
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } 
    else if (pid < 0) 
    {

        perror("shell");
    }
    else
    {
        wait(NULL);
    }
}
