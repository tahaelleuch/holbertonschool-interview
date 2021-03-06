#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: pointer to pointer of first node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/
int is_palindrome(listint_t **head)
{
	int list[10000];
	int count = 0, back = 0;
	int flag = 1;

	while (*head)
	{
		list[count] = (*head)->n;
		*head = (*head)->next;
		count++;
	}
	count--;

	while (count > back && flag != 0)
	{
		if (list[count] != list[back])
			flag = 0;
		count--;
		back++;
	}
	return (flag);
}
