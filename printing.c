#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pall - Print all elements in the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the pall opcode is encountered
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}


/**
 * pint - Print the value at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the pint opcode is encountered
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}



/**
 * pchar - Print the value at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the pint opcode is encountered
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}



/**
 * pstr - Print the value at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the pint opcode is encountered
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
		printf("\n");
	else
	{
		while ((*stack) && ((*stack)->n > 0 && (*stack)->n <= 127))
		{
			if ((*stack)->n == 0)
				break;

			printf("%c", (*stack)->n);

			*stack = (*stack)->next;
		}
		printf("\n");
	}
}
