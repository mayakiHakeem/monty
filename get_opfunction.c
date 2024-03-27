#include <string.h>
#include "monty,h"

/**
 * get_op_f - retrieves the function pointer associated with an opcode
 * @opcode: the opcode string
 *
 * Return: a ptr to the function mapped with the opcode, or NULL if not found
 */
void (*get_op_f(char *opcode))(stack_t **stack, unsigned int line_number)
{
	unsigned int i;

	instruction_t instructions[] = {
		{"push", pusher},
		{"pall", paller},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i].f);
	}
	return (NULL);
}
