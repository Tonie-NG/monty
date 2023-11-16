#include "monty.h"
#include <stdlib.h>

/**
 * swap_func - a function that swaps the integers
 * of the first two elements
 * @head: pointer to the head of a doubly linked list
 * @line_number: current line number of the file
 */
void swap_func(stack_t **head, usint line_number)
{
	stack_t *currenthead = *head;
	usint temp;

	if (*head == NULL && currenthead->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(g_context.file);
		free(g_context.linetext);
		free_stack_list(*head);
		exit(EXIT_FAILURE);
	}

	temp = currenthead->n;
	currenthead->n = currenthead->next->n;
	currenthead->next->n = temp;
}

