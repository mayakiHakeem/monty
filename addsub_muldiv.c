#include "monty.h"

/**
 * add - Handles the add opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty file
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free(global_params->line);
		fclose(global_params->file);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number); /* Remove the top of the stack*/
}
