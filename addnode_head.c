#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * addnode_head - function to add a new node to teh head
 * of a doubly linked list
 * @head: pointer to the head of a doubly linked list
 * @n: integer for the element
 */
void addnode_head(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Memory Allocation failed\n");
		exit(0);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	*head = new_node;
	if (new_node->next != NULL)
	{
		(new_node->next)->prev = new_node;
	}
}

