#include "main.h"

extern char **environ;

void check_env(char **envp)
{
	int i;
	
	for (i = 0; envp[i] != NULL; i++)
	{
		printf("%s\n", envp[i]);
	}
} 
