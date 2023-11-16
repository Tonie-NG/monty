#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push_func - a function that add an element to
 * the head of a linked list
 * @head: pointer to the head of a doubly linked list
 * @line_number: current line number of the file
 */
void push_func(stack_t **head, usint line_number)
{
	int integer = 0;
	int index = 0;
	int temp = 0;

	if (g_context.arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(g_context.file);
		free(g_context.linetext);
		free_stack_list(*head);
		exit(EXIT_FAILURE);
	}

	if (g_context.arg[0] == '-' && g_context.arg[0] == '+')
	{
		index++;
	}

	temp = check_int(g_context.arg);
	if (temp == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(g_context.file);
		free(g_context.linetext);
		free_stack_list(*head);
		exit(EXIT_FAILURE);
	}
	integer = atoi(g_context.arg);
	if (g_context.mode == 0)
	{
		addnode_head(head, integer);
	}
}

/**
 * check_int - function to check that a string is an integer
 * @n: the string to check
 * Return: 1 on error and 0 on success
 */
int check_int(char *n)
{
	int index = 0;

	while (n[index] != '\0')
	{
		if (n[index] > 57 || n[index] < 48)
		{
			return (1);
		}
		index++;
	}

	return (0);
}

