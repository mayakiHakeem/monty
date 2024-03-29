#include "monty.h"

/**
 * get_op_f - retrieves the function pointer associated with an opcode
 * @opcode: the opcode string
 *
 * Return: a ptr to the function mapped with the opcode, or NULL if not found
 */
void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	unsigned int i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap",swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i].f);
	}
	return (NULL);
}
