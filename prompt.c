#include <stdio.h>
#include "shell.h"

/**
 * print_prompt, print_prompt1: prompt for short user input, prompt for long user input spanning multiple lines, respectively.
 *
 * Return (0): Always void
 *
 */

void print_prompt(void)
{
	fputs("$ ", stderr);
}
void print_prompt1(void)
{
	fputs("> ", stderr);
} 
