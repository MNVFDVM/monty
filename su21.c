#include "monty.h"
/**
  *f_sub- sustration
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *a;
	int s, n;

	a = *head;
	for (n = 0; a != NULL; n++)
		a = a->next;
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	a = *head;
	s = a->next->n - a->n;
	a->next->n = s;
	*head = a->next;
	free(a);
}
