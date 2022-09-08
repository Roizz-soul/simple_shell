#include "shell.h"
/**
  * runShell - Interactive shell
  * Return: check code
  */
int runShell()
{
	pid_t my_pid;
	int i, status, j, k = 1;
	ssize_t h = -1, bytes;
	size_t size = 0;
	char *cmd = NULL, *token, *argv[] = {NULL, NULL, NULL, NULL};
	while (k == 1)
	{
		/* Display of our shell, getline stores user input in cmd*/
		i = isatty(STDIN_FILENO);
		if (i == 1)
			write(STDOUT_FILENO, "#cisfun ", 8);
		bytes = getline(&cmd, &size, stdin);
		if (bytes == h)
		{
			k = 0;
			/*kill(getpid(), SIGTERM);*/
			break;
		}

		/* While loop to remove the newline char from cmd */
		i = 0;
		while (cmd[i])
		{
			if (cmd[i] == '\n')
				cmd[i] = '\0';
			i++;
		}
		if (strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			break;
		} else if (strcmp(cmd, "env") == 0 || strcmp(cmd, "printenv") == 0)
		{
			for (i = 0; environ[i] != NULL; i++)
				printf("%s\n", environ[i]);
			break;
		} else
		{
			/* Creating a child process for execve */
			my_pid = fork();
			token = strtok(cmd, " ");
			j = 0;
			while (token != NULL)
			{
				argv[j] = token;
				token = strtok(NULL, " ");
				j++;
			}
			if (my_pid == 0)
			{
				if (execve(argv[0], argv, NULL) == -1)
					perror("./shell");
				free(cmd);
				/*kill(getpid(), SIGTERM);*/
				exit(0);
			} else
				wait(&status);
		}
	}

	return (0);
}
