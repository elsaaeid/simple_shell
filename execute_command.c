/* execute_command.c */
#include "main.h"

/**
 * Function to execute a command
 *
 * Return: 0 on success
 */
int execute_command(char** args) {
    pid_t pid;
    int status;
    
    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {

        perror("shell");
    } else {

        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    
    return 1;
}
