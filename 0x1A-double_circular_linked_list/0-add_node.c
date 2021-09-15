#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>


/**
 * add_node_end - add to the end of a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *my_new_list, *first, *second;

	if (!str)
		return (NULL);

	my_new_list = malloc(sizeof(List));

	if (!my_new_list)
		return (NULL);

	my_new_list->str = strdup(str);

	if (!my_new_list->str)
		return (NULL);

	if ((!list) || (*list == NULL))
	{
		my_new_list->next = my_new_list;
		my_new_list->prev = my_new_list;
		*list = my_new_list;
		return (my_new_list);
	}
	else
	{
		first = *list;
		second = first->prev;
		my_new_list->next = first;
		my_new_list->prev = second;
		second->next = my_new_list;
		first->prev = my_new_list;
		return (my_new_list);
	}

}


/**
 * add_node_begin - Add a new node to the beginning of a double circular linked lis
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *my_new_list, *first, *second;

	if (!str)
		return (NULL);

	my_new_list = malloc(sizeof(List));

	if (!my_new_list)
		return (NULL);

	my_new_list->str = strdup(str);

	if (!my_new_list->str)
		return (NULL);
        
	if ((!list) || (!*list))
	{
		my_new_list->next = my_new_list;
		my_new_list->prev = my_new_list;
		*list = my_new_list;
		return (my_new_list);
	}
	else
	{
		first = *list;
		second = first->prev;
		my_new_list->next = first;
		my_new_list->prev = second;
		second->next = my_new_list;
		first->prev = my_new_list;
		*list = my_new_list;
		return (my_new_list);
	}
}
