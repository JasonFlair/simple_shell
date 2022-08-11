#include "main.h"

/**
 * check_env - a function to print
 * the env
 * @envp: env pointer
 * Return: none.
 */

void check_env(char **envp)
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		printf("%s\n", envp[i]);
	}
}
