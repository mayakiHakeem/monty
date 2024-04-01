#include "monty.h"

/**
 * cleanup - free the stack
 */
void cleanup(void)
{
	param *global_params = get_global_params();

	free_stack(global_params->stack);
	global_params->stack = NULL;
	
	if (global_params->file != NULL)
	{
		fclose(global_params->file);
		global_params->file = NULL;
	}
}

/**
 * free_stack - free the stack
 * @stack: stack to free
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
