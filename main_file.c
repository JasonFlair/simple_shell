#include "main.h"

int main(int argc, char **argv[])
{
    shell_loop(); /* function to run in a loop */

    return EXIT_SUCCESS;
}

void shell_loop(void) /* loop function */
{
    char *gotten_line;
    char **args;
    int status;

    do
    {
        printf("> ");
        gotten_line = read_line();
        args = split_line(gotten_line);
        status = execute_shell(args);

        free(gotten_line);
        free(args);
    } while (status);
}