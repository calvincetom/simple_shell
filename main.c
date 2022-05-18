#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "shell.h"
/**
 * main: prompt user input and output, with memory management
 * and implements the REPL loop
 * If the command is empty 
 * i.e. the user pressed ENTER without writing anything,
 * we skip this input and continue with the loop.
 * If the command is exit, we exit the shell.
 * Otherwise, we echo back the command,
 * free the memory we used to store the command,
 * and continue with the loop.
 * print_prompt: prints the prompt string '$'.
 * print_prompt1: prints the prompt string '>' when a new line is detected.
 * read_cmd: reads the next line of input.
 *
 * Return (1): Always return 1, for success;
 */

int main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	char *cmd;

	do {
		print_prompt();
		cmd = read_cmd();
		if (!cmd)
		{
			exit(EXIT_SUCCESS);
		}
		if (cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
		{
			free(cmd);
			continue;
		}
		if (strcmp(cmd, "exit\n") == 0)
		{
			free(cmd);
			break;
		}
		printf("%s\n", cmd);
		free(cmd);
	} while (1);
	exit(EXIT_SUCCESS);
}
char *read_cmd(void)
{
	char buf[1024];
	char *ptr = NULL;
	char ptrlen = 0;

	while (fgets(buf, 1024, stdin))
	{
		int buflen = strlen(buf);

		if (!ptr)
		{
			ptr = malloc(buflen + 1);
		}
		else
		{
			char *ptr2 = realloc(ptr, ptrlen+buflen + 1);

			if (ptr2)
			{
				ptr = ptr2;
			}
			else
			{
				free(ptr);
				ptr = NULL;
			}
		}

		if (!ptr)
		{
			fprintf(stderr, "error: failed to alloc buffer: %s\n",
					strerror(errno));
			return (NULL);
		}

		strcpy(ptr + ptrlen, buf);

		if (buf[buflen - 1] == '\n')
		{
			if (buflen == 1 || buf[buflen - 2] != '\\')
			{
				return (ptr);
			}

			ptr[ptrlen + buflen - 2] = '\0';
			buflen -= 2;
			print_prompt1();
		}

		ptrlen += buflen;
	}

	return ptr;
}
