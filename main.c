#include "shell.h"

/**
  * main - shell code
  * Return: 0
  */
int main(void)
{
	while (1)
	{
		char *line;
		char **tokens;

		printf("My_shell:$ ");

		line = read_line();
		tokens = split_line(line);

		if (tokens[0] != NULL)
			shell_exec(tokens);
		free(tokens);
		free(line);
	}
	return (0);
}
