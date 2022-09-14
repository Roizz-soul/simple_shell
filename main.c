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
		int i;

		i = isatty(STDIN_FILENO);
		if (i == 1)
			write(1, "My_shell:$ ", 11);

		line = read_line();
		if (line == NULL)
		{
			break;
		}
		tokens = split_line(line);

		if (tokens[0] != NULL)
			shell_exec(tokens);
		free(tokens);
		free(line);
	}
	return (0);
}
