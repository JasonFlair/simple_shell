#include "main.h"

int main(__attribute__ ((unused))int argc, __attribute__ ((unused))char **argv, char * envp[])
{
    shell_loop(envp); /* function to run in a loop */

    return EXIT_SUCCESS;
}

void shell_loop(char ** envp) /* loop function */
{
    char *gotten_line;
    char **args;
    int status;

    do
    {
        printf("> ");
        gotten_line = read_line();
        args = split_line(gotten_line);

        if (args[0] != NULL)
        {
            if (strcmp(args[0], "env") == 0)
            {
                check_env(envp);
            }
            else
            {
                status = shell_execute(args);
            }
        }

        free(gotten_line);
        free(args);
    } while (1);
}
