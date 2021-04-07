#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: The array to be printed
 * @size: Size of the array
 * Return: the root of the new avl
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (array == NULL || size <= 0)
		return (NULL);

	root = create_new_node(array, 0, size - 1, NULL);
	return (root);
}

/**
 * create_new_node - create a new node
 * @array: The array to be printed
 * @start: the start index
 * @end: the end index
 * @parent: pointer to the parent of the node
 * Return: the root of the new node
*/
avl_t *create_new_node(int *array, size_t start, size_t end, avl_t *parent)
{
	avl_t *node;
	size_t mid;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);
	mid = (start + end) / 2;
	node->n = array[mid];
	node->parent = parent;

	if (mid != start)
		node->left = create_new_node(array, start, mid - 1, node);
	else
		node->left = NULL;

	if (mid != end)
		node->right = create_new_node(array, mid + 1, end, node);
	else
		node->right = NULL;

	return (node);
}
