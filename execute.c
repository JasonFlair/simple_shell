#include "main.h"

int shell_execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    /* if ann empty command was entered. */
    return 1;
  }

  for (i = 0; i < shell_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return shell_launch(args);
}