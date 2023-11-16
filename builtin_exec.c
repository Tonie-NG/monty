#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * builtin_exec - function that executes
 * another function based on the input
 * @linetext: the string of a current line
 * @head: the head of a doubly linked list
 * @line_count: the current line in the file
 * @file: a pointer to the file input
 * Return: 0 on success and 1 on error
 */
int builtin_exec(char *linetext, stack_t **head, usint line_count, FILE *file)
{

	usint index;
	char *command;
	instruction_t optstru[] = {
			{"push", push_func},
			{"pall", pall_func},
			{"pint", pint_func},
			{"pop", pop_func},
			{"swap", swap_func},
			{"add", add_func},
			{"nop", nop_func},
			{NULL, NULL},
	};
	command = strtok(linetext, " \n\t");
	if (command && command[0] == '#')
	{
		return (1);
	}
	g_context.arg = strtok(NULL, " \n\t");
	for (index = 0; command && optstru[index].opcode != NULL; index++)
	{
		if (strcmp(command, optstru[index].opcode) == 0)
		{
			optstru[index].f(head, line_count);
			return (0);
		}
	}
	if (command && optstru[index].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_count, command);
		fclose(file);
		free(linetext);
		free_stack_list(*head);
		exit(EXIT_FAILURE);
	}
	return (1);
}

