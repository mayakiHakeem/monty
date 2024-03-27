#include <stdlib.h>
#include <string.h>
#include "monty.h"
#include <stdio.h>
#include <stddef.h>

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0, line_number = 0;
	ssize_t read;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	while ((read = getline(&line, &len, file)) != -1)
	{
		// Process the line
		// ...

		line_number++; // Increment line_number after processing the line
	}

	free(line);
	fclose(file);
	return (0);
}
