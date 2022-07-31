#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
//#include <sys/wait.h>
#include <string.h>

#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

void shell_loop(void);
char *read_line(void);
char **split_line(char *line);
ssize_t getline();

#endif 
