#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
*/
int check_cycle(listint_t *list)
{
	listint_t *one, *two;

	if (!list)
		return (0);
	one = list;
	two = list->next;
	while (one && two && two->next)
	{
		one = one->next;
		two = two->next->next;
		if (one == two)
			return (1);
	}
	return (0);
}
