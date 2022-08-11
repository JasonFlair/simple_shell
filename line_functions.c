#include "main.h"

char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    ssize_t getlinefunc = getline(&line, &bufsize, stdin); /* getline allocates memory */

    if (getlinefunc == -1)
    {
        if (feof(stdin))
        {
            exit(EXIT_SUCCESS); /* we got an eof */
        }
        else
        {
            perror("readline?");
            exit(EXIT_FAILURE);
        }
        
    }
    return line;
}
char **split_line(char *line)
{
    int bufsize = TOK_BUFSIZE, i = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "shell: error in allocation\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOK_DELIM);
    while (token != NULL)
    {
        tokens[i] = token;
        i++;

        if (i >= bufsize)
        {
            bufsize += TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens)
            {
             fprintf(stderr, "shell: error in allocation\n");
            }
        }
        token = strtok(NULL, TOK_DELIM);
    }
    tokens[i] = NULL;
    return tokens;
}
