#include "main.h"

int shell_cd(char **args);
int shell_help();
int shell_exit();

char *builtin_str[256] = {
  "cd",
  "help",
  "exit"
};
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
int shell_help(__attribute__ ((unused))char **args)
{
  int i;
  printf("Jason and Emmanuel's shell\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; func[i].str != NULL; i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}
int shell_exit(__attribute__ ((unused))char **args)
{
  return 0;
}
