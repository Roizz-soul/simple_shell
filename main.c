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
		char **stokens;
		int i;

		i = isatty(STDIN_FILENO);
		if (i == 1)
			write(1, "My_shell:$ ", 11);

		line = read_line();
		if (line == NULL)
		{
			/*free(line);*/
			break;
		}
		stokens = split_line(line);

		if (stokens[0] != NULL)
			shell_exec(stokens);
		free(stokens);
		free(line);
	}
	return (0);
}
