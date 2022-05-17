#include <stdio.h>
#include "shell.h"
void print_prompt(void)
{
	fputs("$ ", stderr);
}
void print_prompt1(void)
{
	fputs("> ", stderr);
} 
