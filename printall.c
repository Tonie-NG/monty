#include "monty.h"
/**
 * pall_func - prints the stack
 * @head: stack head
 * @line_number: Currrent line number
 */
void pall_func(stack_t **head, usint line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *head;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

