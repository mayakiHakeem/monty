#include "monty.h"

param *global_params = NULL;

/**
 * initialize_params - initialize the global params
 *
 * Return: void
 */
void initialize_params(void)
{
	/* Allocate memory for global_params if it's NULL */
	if (global_params == NULL)
	{
		global_params = malloc(sizeof(param));
		if (global_params == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
	}

	/* Initialize the members of global_params*/
	global_params->line_number = 1;
	global_params->arg = NULL;
	global_params->n = 0;
	global_params->file = NULL;
	global_params->stack = NULL;
	global_params->line = NULL;
}
