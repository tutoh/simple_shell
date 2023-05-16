#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_LENGTH 100

/**
 * simple_shell-calls the shell function
 *
 *Return: Nothing.
*/
void simple_shell(void)
{
	char command[MAX_LENGTH];

	while (1)
	{
		printf("#cisfun$ ");

	if (fgets(command, sizeof(command), stdin) == NULL)
	{
	printf("\n");
	exit(0); /*print a new line after Ctrl+D is pressed*/
	}
	size_t command_length = strlen(command);

	if (command[command_length - 1] == '\n')
	{
		command[command_length - 1] = '\0';  /* Remove the newline character*/
	}
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(1);
	} else if (pid == 0)
	{
	execlp(command, command, NULL);
	/* Executing the command failed*/
	fprintf(stderr, "./shell: %s: No such file or directory\n", command);
	exit(1);
	}
	else
	{
	wait(NULL);
	}
	}
}

/**
 * main-calls the main function
 *
 * Return: void
*/
int main(void)
{
	simple_shell();
	return (0);
}

