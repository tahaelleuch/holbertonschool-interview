#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: the head of linked list
 * Return: the node where the loop starts
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *one, *two;

	if (head == NULL)
		return (0);

	one = head;
	two = head;

	do {
		one = one->next;
		if (one == NULL)
			return (NULL);
		one = one->next;
		if (one == NULL)
			return (NULL);
		two = two->next;
	} while (one != two);

	one = head;

	for (; one != two; )
	{
		two = two->next;
		one = one->next;
	}

	return (one);
}
