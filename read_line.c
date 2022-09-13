#include "shell.h"
/**
  * read_line - reads user input with getline
  * Return: returns the line
  */
char *read_line(void)
{
	char *line = NULL;
	size_t buffer = 0;

	getline(&line, &buffer, stdin);
	return (line);
}
