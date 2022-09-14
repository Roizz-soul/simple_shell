#include "shell.h"
/**
  * read_line - reads user input with getline
  * Return: returns the line
  */
char *read_line(void)
{
	char *cmdline = NULL;
	size_t buffer = 0;
	ssize_t ret;
	int i;

	ret = getline(&cmdline, &buffer, stdin);
	if (ret == -1)
	{
		free(cmdline);
		return(NULL);
	}
	i = 0;
	while (cmdline[i])
	{
		if (cmdline[i] == '\n')
			cmdline[i] = '\0';
		i++;
	}
	/*if (access(cmdline, F_OK) == -1)
	{
		free(cmdline);
		return ("jk");
	}*/
	return (cmdline);
}
