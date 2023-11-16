#ifndef MONTY_H
#define MONTY_H

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
#include <stdio.h>
typedef unsigned int usint;
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
 * struct gs_context - args, file, linetext
 * @arg: value
 * @file: pointer to the monty file
 * @linetext: line content
 * @mode: indicates stack or queue
 * if mode = 0 we are dealing with a stack
 * if mode = 1 we are dealing with a queue
 * default is the stack
 *
 * Description: Maintains and carries a global context
 * or value through out the program.
 */
typedef struct gs_context
{
	char *arg;
	FILE *file;
	char *linetext;
	int mode;
} gt_context;
extern gt_context g_context;

/**
 * function that executes each line of the montyfile
 */
int builtin_exec(char *linetext, stack_t **head, usint line_c, FILE *file);
void push_func(stack_t **head, usint line_number);
void addnode_head(stack_t **head, int n);
void pall_func(stack_t **head, usint line_number);
void pint_func(stack_t **head, usint line_number);
void pop_func(stack_t **head, usint line_number);
void swap_func(stack_t **head, usint line_number);
void add_func(stack_t **head, usint line_number);
void nop_func(stack_t **head, usint line_number);
int check_int(char *n);
void free_stack_list(stack_t *head);

#endif /*!MONTY_H*/

