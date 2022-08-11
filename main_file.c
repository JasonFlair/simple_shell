#include "main.h"

/**
 * shell_loop- a function causes a continous loop
 * until shell is exited.
 * @arc:argument count.
 * @argv: array of pointers.
 * Return: void.
*/

int main(__attribute__ ((unused))int argc, __attribute__ ((unused))char **argv)
{
    shell_loop(); /* function to run in a loop */

    return EXIT_SUCCESS;
}
void shell_loop() /* loop function */
{
    char *gotten_line;
    char **args;
    int status;
    int isPipe = 0;
    
    do
    {
        if (isatty(fileno(stdin)))
        {
            printf("> ");
            isPipe = 1;
        }
        gotten_line = read_line();
        args = split_line(gotten_line);
        status = shell_execute(args);
        
        free(gotten_line);
        free(args);
    } while (status && isPipe);
}
