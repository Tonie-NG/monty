#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pint_func - a function that prints the top element
 * in doubly linked list
 * @head: pointer to the head of a doubly linked list
 * @line_number: current line number of the file
 */
void pint_func(stack_t **head, usint line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(g_context.file);
		free(g_context.linetext);
		free_stack_list(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

