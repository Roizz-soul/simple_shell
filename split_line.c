#include "shell.h"
/**
  * split_line - splits a line into words / tokens
  * @line: line to be splitted
  * Return: tokens
  */
char **split_line(char *line)
{
	int length = 0, capacity = 16;
	char **tokens = malloc(capacity * sizeof(char *));
	char *delimiters = " \t\r\n";
	char *token = strtok(line, delimiters);

	while (token != NULL)
	{
		tokens[length] = token;
		length++;

		if (length >= capacity)
		{
			capacity = (int) (capacity * 1.5);
			tokens = realloc(tokens, capacity * sizeof(char *));
		}

		token = strtok(NULL, delimiters);
	}
	tokens[length] = NULL;
	/*if (access(tokens[0], F_OK) == -1)
	{
		free(tokens);
		tokens = NULL;
	}*/
	return (tokens);
}
