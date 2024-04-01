#include "monty.h"

/**
 * process - process the non-empty line
 * @opcode: instruction code in the line
 * @arg: argument received by opcode
 * @line_number: number of the line under processing
 */
void process(char *opcode, char *arg, unsigned int line_number)
{
	void (*handle)(stack_t **stack, unsigned int line_number);

	handle = get_func(opcode);

	if (handle != NULL)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (arg == NULL)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			handle(&(get_global_params()->stack), line_number);
		}
		else
			handle(&(get_global_params()->stack), line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
