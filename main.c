#include "shell.h"
/**
  * main - Entry point
  * Return: check code
  */
int main(void)
{
	pid_t my_pid;
	int i, status;
	ssize_t h = -1, bytes;
	size_t size = 0;
	char *cmd, *argv[] = {NULL, NULL, NULL, NULL};
	/* Display of our shell, getline stores user input in cmd */
	printf("#cisfun ");
	bytes = getline(&cmd, &size, stdin);
	if (bytes == h)
		exit(0);
	/* While loop to remove the newline char from cmd */
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\n')
			cmd[i] = '\0';
		i++;
	}
	/* Creating a child process for execve */
	my_pid = fork();
	argv[0] = cmd;
	if (my_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("Failed");
	} else
	{
		if (bytes == h)
			exit(0);
		wait(&status);
	}
	main();

	return (0);
}
