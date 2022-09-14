#include "shell.h"
/**
  * read_line - reads user input with getline
  * Return: returns the line
  */
char *read_line(void)
{
	char *line = NULL;
	size_t buffer = 0;
	ssize_t ret;

	ret = getline(&line, &buffer, stdin);
	if (ret == -1)
		return(NULL);
	return (line);
}
