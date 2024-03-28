#include "monty.h"

/**
 * main - Monty byte cocde interpreter
 * @argc: argument counter
 * @argv: argument vector
 * Return: an integer value 1 on error otherwise 0;
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	initialize_params();
	while ((read = getline(&line, &len, file)) != -1)
	{
		if (line == NULL || line[0] == '#' || strcmp(line, "\n") == 0)
			continue;

		char *opcode = strtok(line, " \t\n");
		global_params->arg = strtok(NULL, " \t\n");
		void (*handle)(stack_t **stack, unsigned int line_number) = get_func(opcode);

		if (handler != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (global_params->arg == NULL)
				{
					fprintf(stderr, "L%u: usage: push integer\n", global_params->line_number);
					free(line);
					fclose(file);
					exit(EXIT_FAILURE);
				}
				handle(&(global_params->stack), global_params->line_number);
			}
			else
				handler(&(global_params->stack), global_params->line_number);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", global_params->line_number, opcode);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		global_params->line_number++;

	}

	free(line);
	fclose(file);
	return (0);
}
