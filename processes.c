#include "main.h"

int launch_shell(char **args)
{
    pid_t child_pid
    pid_t wpid;
    int status;

    child_pid = fork();

    if (child_pid == 0) {
    if (execvp(args[0], args) == -1) /*if executuion fails*/ {
      perror("shell error"); /* print error, else execute */
    }
    exit(EXIT_FAILURE);
  } else if (child_pid < 0) { /* if no child process */
    perror("nothing forked");
  } else {
    do {
      wpid = waitpid(child_pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}
