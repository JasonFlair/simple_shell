#include "main.h"

int shell_cd(char **args);
int shell_help(void);
int shell_exit(void);

char *builtin_str[256] = {
	"cd",
	"help",
	"exit"
};
/**
 * shell_cd - a function for changing
 * directories.
 * @args: argument handled
 * Return: 1.
*/
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
	return (1);
}
/**
 * shell_help - prints a message for help
 * @args: argument handled
 * Return: 1.
*/
int shell_help(void)
{
	int i;

	printf("Jason and Emmanuel's shell\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");
	for (i = 0; builtin_str[i] != NULL; i++)
	{
	printf("  %s\n", builtin_str[i]);
	}
	printf("Use the man command for information on other programs.\n");
	return (1);
}
/**
 * shell_exit - exits shell
 * @args: argument handled
 * Return: 1.
*/
int shell_exit(void)
{
	return (0);
}
