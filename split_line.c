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
	char *delimiters = " \t\r\n", tch[20] = "";
	char *token = strtok(line, delimiters);

	if (access(token, F_OK) == -1)
	{
		strcat(tch, "/bin/");
		strcat(tch, token);
	}
	while (token != NULL)
	{
		if (length == 0 && tch[0] != '\0')
			tokens[length] = tch;
		else
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
		tch = tokens[0];
		tokens[0] = realloc(tokens[0], (sizeof(tch) + sizeof("/bin/")));
		tokens[0] = "/bin/";
		strcat(tokens[0], tch);
	*/
	return (tokens);
}
