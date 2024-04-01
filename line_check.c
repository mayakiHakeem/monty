#include "monty.h"

/**
 * is_empty_line - Checks if line is empty
 * @line: line to check
 * Return: 1 if line is empty, otherwise 0.
 */
int is_empty_line(char *line)
{
	while (*line != '\0')
	{
		if (!isspace((unsigned char)*line))
			return (0);
		line++;
	}
	return (1);
}


/**
 * trim_str - remove leading white space
 * @str: string to trim
 *
 * Return: trimmed str
 */
char *trim_str(char *str)
{
	while (str && isspace(*str))
		str++;

	return (str);
}
