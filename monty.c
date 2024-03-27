#include <stdlib.h>
#include <string.h>
#include "monty.h"
#include <stdio.h>
#include <stddef.h>

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0, line_number = 1;
	ssize_t read;
	FILE *file = NULL;

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
	while ((read = getline(&line, &len, file)) != -1)
	{
		if (line == NULL || line[0] == '#' || strcmp(line, "\n") == 0)
			continue;
		char *opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");
		void (*handle)(stack_t **stack, unsigned int line_number) = get_op_f(opcode);

		if (handler != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (arg == NULL)
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					free(line);
					fclose(file);
					exit(EXIT_FAILURE);
				}
				else
					handle(&stack, line_number);
			}
			else
				handler(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}

	free(line);
	fclose(file);
	return (0);
}
