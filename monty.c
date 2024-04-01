#include <stdio.h>
#include "monty.h"

/**
 * main - Monty byte cocde interpreter
 * @argc: argument counter
 * @argv: argument vector
 * Return: an integer value 1 on error otherwise 0;
 */
int main(int argc, char *argv[])
{
	char buffer[BUFFER_SIZE];
	char *opcode;
	param *global_params = get_global_params();

	initialize_params();
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	global_params->file = fopen(argv[1], "r");
	if (global_params->file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, BUFFER_SIZE, global_params->file) != NULL)
	{
		global_params->line = buffer;
		if (global_params->line[0] == '#')
			continue;
		if (is_empty_line(global_params->line))
		{
			global_params->line_number++;
			continue;
		}

		opcode = strtok(global_params->line, " \t\n");
		global_params->arg = strtok(NULL, " \t\n");

		process(opcode, global_params->arg, global_params->line_number);
		global_params->line_number++;

	}

	cleanup();
	return (0);
}
