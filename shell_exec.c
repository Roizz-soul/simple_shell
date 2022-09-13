#include "shell.h"
/**
  * struct builtin - yeah
  * struct builtin builtins - yeah
  * Description: funcion selecter
  */
struct builtin builtins[] = {
	{"help", _help},
	{"exit", My_exit},
	{"cd", _cd},
};
/**
  * num_of_builtins - number of builtins
  * Return: integer
  */
int num_of_builtins(void)
{
	return (sizeof(builtins) / sizeof(struct builtin));
}
/**
  * shell_exec - executes commands
  * @args: command and arguments
  */
void shell_exec(char **args)
{
	pid_t child_pid;
	int i;

	for (i = 0; i < num_of_builtins(); i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
			return;
		}
	}

	child_pid = fork();

	if (child_pid == 0)
	{
		execvp(args[0], args);
		perror("Error");
		exit(1);
	}
	else if (child_pid > 0)
	{
		int status;

		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
		perror("Error");
}
