#include "monty.h"

/**
 * push - Pushes a value onto the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 * @arg: String representation of the value to be pushed
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;

	if (!arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (an_int(arg))
		value = atoi(arg);
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (push_helper(stack, value) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * push_helper - Pushes a value onto the stack
 * @stack: Double pointer to the stack
 * @value: Value to be pushed
 *
 * Return: Pointer to the new node, or NULL on failure
 */
stack_t *push_helper(stack_t **stack, int value)
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


/**
 * pop - Handles the pop opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)  /* Check if stack is empty*/
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(line);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;  /* Move the stack pointer to the next node*/
	if (*stack != NULL)
		(*stack)->prev = NULL;  /* Update the prev pointer of the new top node*/
	free(temp);
}


/**
 * an_int - check if string is int
 * @str: string to convert
 *
 * Return: 1 if int | 0 if not all int
 */
int an_int(char *str)
{
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
