#include "main.h"

int shell_execute(char **args)
{
  int i;
  builtins func[] = {
  {"cd", shell_cd},
  {"help", shell_help},
  {"exit", shell_exit},
  {NULL, NULL}
};

  if (args[0] == NULL) {
    /* if an empty command was entered. */
    return 1;
  }

  for (i = 0; func[i].str != NULL; i++) {
    if (strcmp(args[0], func[i].str) == 0) {
      return func[i].f(args);
    }
  }

  return shell_launch(args);
}