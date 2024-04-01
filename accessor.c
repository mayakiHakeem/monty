#include "monty.h"

/* Define global_params as a static variable */
static param global_params_instance;

/* Accessor function to get the global_params instance */
param *get_global_params(void)
{
	return (&global_params_instance);
}
