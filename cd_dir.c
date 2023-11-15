/* cd_dir.c */
#include "main.h"

/**
 * cd_dir is function to enter to path of current directory
 * @args
 * Return: directory
 */
void cd_dir(char** args) {
    if (args[1] == NULL)
    {
        fprintf(stderr, "shell: expected argument to \"cd\"\n");
    } 
    else 
    {
        if (chdir(args[1]) != 0)
        {
            perror("shell");
        }
    }
}
