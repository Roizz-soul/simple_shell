#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
/**
  * struct builtin - a builtin structure
  * Description: for builtin commands
  * @name: name of builtin
  * @func: function to execute
  */
struct builtin
{
	char *name;
	void (*func)(char **args);
};
char *read_line(void);
char **split_line(char *line);
void shell_exec(char **args);
char **environ;
void My_exit(char **args);
void _cd(char **args);
void _help(char **args);

#endif
