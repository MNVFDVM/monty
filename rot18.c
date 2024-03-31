#include "monty.h"
/**
  *f_rotl- rotates the stack to the top
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *t = *head, *a;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	a = (*head)->next;
	a->prev = NULL;
	while (t->next != NULL)
	{
		t = t->next;
	}
	t->next = *head;
	(*head)->next = NULL;
	(*head)->prev = t;
	(*head) = a;
}
