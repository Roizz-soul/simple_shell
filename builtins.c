#include "shell.h"
/**
  * My_exit - exits the shell
  * @args: argument
  */
void My_exit(char __attribute__ ((unused)) **args)
{
	exit(0);
}
/**
  * _cd - change working directory
  * @args: argument
  */
void _cd(char **args)
{
	if (args[1] == NULL)
		printf("Error: missing argument\n");
	else
	{
		if (chdir(args[1]) != 0)
			perror("Error: cd");
	}
}
/**
  * _help - help
  * @args: argument
  */
void _help(char __attribute__ ((unused)) **args)
{
	char *helptext = "My_shell - the Simple shell.\n"
		"The following commands are available:\n"
		"cd	Change the working directory.\n"
		"exit	Exit the shell.\n"
		"help	Print this help text.\n";
	printf("%s", helptext);
}
