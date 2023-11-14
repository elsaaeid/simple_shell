//execute_command.c
#include "main.h"

/**
 * Function to execute a command
 *
 * Return: 0 on success
 */
int execute_command(char** args) {
    pid_t pid, wpid;
    int status;
    
    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("shell");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    
    return 1;
}
