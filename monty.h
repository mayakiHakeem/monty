#ifndef MONTY_H
#define MONTY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct params - opcode and its function
 * @line_number: number of line
 * @arg: argument
 * @n: data
 * @file: monty bytecode file
 * @stack: pointer stack
 * @line: current line read
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct params
{
	unsigned int line_number;
	char *arg;
	int n;
	FILE *file;
	stack_t *stack;
	char *line;
} param;

extern param *get_global_params(void);

void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number);
void initialize_params(void);
void push(stack_t **stack, unsigned int line_number);
stack_t *push_helper(stack_t **stack, int value);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
int an_int(char *str);
void nop(stack_t **stack, unsigned int line_number);
int is_empty_line (char *line);
void free_stack(stack_t *stack);
void cleanup(void);

#endif
