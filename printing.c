#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pall_handler - Print all elements in the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the pall opcode is encountered
 */
void pall_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	printf("Current stack:\n");
	while (current != NULL) {
		printf("%d\n", current->n);
		current = current->next;
	}
}


/**
 * pint_handler - Print the value at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the pint opcode is encountered
 */
void pint_handler(stack_t **stack, unsigned int line_number) {
	if (*stack == NULL) {
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
