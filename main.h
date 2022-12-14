#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

  char *gotten_line;
	char **args;
	int status;

void shell_loop(void);
char *read_line(void);
char **split_line(char *line);
void check_env(char **envp);
ssize_t getline();
int shell_cd(char **args);
int shell_help(__attribute__ ((unused))char **args);
int shell_exit(__attribute__ ((unused))char **args);
int shell_launch(char **args);
int shell_execute(char **args);
int shell_num_builtins(void);
char *builtin_str[256];

typedef struct builtins
{
  char *str;
  int (*f)(char **arg);
} builtins;

#endif 
