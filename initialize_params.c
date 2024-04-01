#include "monty.h"

/**
 * initialize_params - initialize the global params
 *
 * Return: void
 */
void initialize_params(void)
{
	param *global_params = get_global_params();

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
