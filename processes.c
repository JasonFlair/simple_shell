#include "main.h"

void launch_shell()
{
    pid_t child_pid = fork();
    pid_t wpid;
    int status;

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
