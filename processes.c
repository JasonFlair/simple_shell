#include "main.h"

int shell_launch(char **args, char **envp)
{
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid == 0) {
    if (execve(args[0], args, envp) == -1) /*if executuion fails*/ {
      perror("shell error"); /* print error, else execute */
    }
    exit(EXIT_FAILURE);
  } else if (child_pid < 0) { /* if no child process */
    perror("nothing forked");
  } else {
    do {
      waitpid(child_pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}
