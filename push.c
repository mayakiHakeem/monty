#include <stdlib.h>
#include "monty.h"

/**
 * pusher - Pushes a value onto the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 * @arg: String representation of the value to be pushed
 */
void pusher(stack_t **stack, unsigned int line_number)
{
	int value;

	if (!arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);

	if (value == 0 && strcmp(arg, "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (pusher_help(stack, value) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * pusher_help - Pushes a value onto the stack
 * @stack: Double pointer to the stack
 * @value: Value to be pushed
 *
 * Return: Pointer to the new node, or NULL on failure
 */
stack_t *pusher_help(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}

	return (new_node);
}
