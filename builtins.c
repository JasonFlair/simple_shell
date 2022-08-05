#include "main.h"

int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);

int shell_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}
int shell_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "shell: expected argument to \"cd\"\n");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("cd error");
        }
    }
    return 1;
}
int shell_help(char **args)
{
  int i;
  printf("Jason and Emmanuel's shell\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < shell_num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}
int shell_exit(char **args)
{
  return 0;
}