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
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number); /* Remove the top of the stack*/
}



/**
 * sub - Handles the add opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number); /* Remove the top of the stack*/
}



/**
 * mul - Handles the add opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number); /* Remove the top of the stack*/
}



/**
 * division - Handles the add opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty file
 */
void division(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n != 0)
	{
		(*stack)->next->n /= (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
}



/**
 * mod - Handles the add opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty file
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n != 0)
	{
		(*stack)->next->n %= (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
}
