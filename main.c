#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

gt_context g_context = {NULL, NULL, NULL, 0};

/**
 * main - entry point of the program
 * @argv: An array of user input
 * @argc: number of inputs
 *
 * Return: 0 if successfull and 1 on Error
 *
 * Description: Parses user input which ideally
 * should be a file, reads the file and recursively
 * calls the builtin_exec function to excute each line
 */
int main(int argc, char *argv[])
{
	char *line = NULL, *filename;
	FILE *file;
	size_t len = 0;
	size_t read_line = 1;
	size_t tester = -1;
	stack_t *stack = NULL;
	usint line_count = 0;

	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read_line = getline(&line, &len, file)) != tester)
	{
		g_context.linetext = line;
		line_count++;
		builtin_exec(line, &stack, line_count, file);
	}
	free(line);
	free_stack_list(stack);
	fclose(file);
	return (0);
}

/**
 * free_stack_list - recursively frees a doubly linked list
 * @head: head of the stack
 */
void free_stack_list(stack_t *head)
{
	stack_t *new_head;

	new_head = head;
	while (head)
	{
		new_head = head->next;
		free(head);
		head = new_head;
	}
}

