#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop_func -  A function that removes the top element from a stack
 * @head: pointer to the head of a doubly linked list
 * @line_number: current line number of the file
 */
void pop_func(stack_t **head, usint line_number)
{
	stack_t *current_head = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(g_context.file);
		free(g_context.linetext);
		free_stack_list(*head);
		exit(EXIT_FAILURE);
	}

	*head = current_head->next;

	free(current_head);
}

