#include "main.h"

int shell_execute(char **args)
{
  int i;

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