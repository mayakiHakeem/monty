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
	void (*handle)(stack_t **stack, unsigned int line_number);
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
		if (global_params->line[0] == '#' || global_params->line[0] == '\n')
			continue;

		opcode = strtok(global_params->line, " \t\n");
		global_params->arg = strtok(NULL, " \t\n");

		handle = get_func(opcode);
		if (handle != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (global_params->arg == NULL)
				{
					fprintf(stderr, "L%u: usage: push integer\n", global_params->line_number);
					fclose(global_params->file);
					exit(EXIT_FAILURE);
				}
				handle(&(global_params->stack), global_params->line_number);
			}
			else
				handle(&(global_params->stack), global_params->line_number);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", global_params->line_number, opcode);
			fclose(global_params->file);
			exit(EXIT_FAILURE);
		}
		global_params->line_number++;

	}

	fclose(global_params->file);
	return (0);
}
