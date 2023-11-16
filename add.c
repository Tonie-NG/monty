#include "monty.h"
#include <stdlib.h>

/**
 * add_func - function to add the integer value of the
 * top two elements
 * @head: pointer to the head of a doubly linked list
 * @line_number: current line number of the file
 */

void add_func(stack_t **head, usint line_number)
{
	stack_t *currenthead = *head;
	usint temp;

	if (*head == NULL && currenthead->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack empty\n", line_number);
		fclose(g_context.file);
		free(g_context.linetext);
		free_stack_list(*head);
		exit(EXIT_FAILURE);
	}

	temp = currenthead->n;
	currenthead->n = currenthead->next->n;
	currenthead->next->n += temp;
	pop_func(head, line_number);
}

