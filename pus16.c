#include "monty.h"

/**
 * f_push - Add node to the stack or queue
 * @head: Pointer to the head of the stack or queue
 * @counter: Line number
 * Return: No return value
 */
void f_push(stack_t **head, unsigned int counter)
{
	if (!bus.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	int j = 0;
	int is_negative = 0;
	if (bus.arg[j] == '-')
	{
		is_negative = 1;
		j++;
	}

	for (; bus.arg[j] != '\0'; j++)
	{
		if (!isdigit(bus.arg[j]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}

	int n = atoi(bus.arg + is_negative);

	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
