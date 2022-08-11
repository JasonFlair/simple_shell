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
        if (isatty(fileno(stdin)))
        {
            printf("> ");
        }
        gotten_line = read_line();
        args = split_line(gotten_line);
        status = shell_execute(args);

        free(gotten_line);
        free(args);
    } while (status);
}
