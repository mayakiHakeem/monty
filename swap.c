#include "monty.h"

/**
 * swap - Handles the swap opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)  /*stack doesnt have 2 nodes*/
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(line);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	int temp = (*stack)->n;  // Store the value of the top node
	(*stack)->n = (*stack)->next->n;  // Swap values of top two nodes
	(*stack)->next->n = temp;
}
