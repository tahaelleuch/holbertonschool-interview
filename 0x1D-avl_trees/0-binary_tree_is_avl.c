#include "binary_trees.h"

/**
 * bst_check - checks if valid BST
 * @tree: pointer to root node being checked
 * @min: integer
 * @max: integer
 * Return: 1 if valid BST, 0 on failure
 */
int bst_check(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (bst_check(tree->left, min, tree->n - 1) &&
		bst_check(tree->right, tree->n + 1, max));
}

/**
 * bst - checks if valid BST
 * @tree: pointer to root node of tree to check
 * Return: 1 if valid BST, else 0
 */
int bst(const binary_tree_t *tree)
{
	return (bst_check(tree, INT_MIN, INT_MAX));
}

/**
 * get_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of tree, 0 if NULL
 */
size_t get_tree_height(const binary_tree_t *tree)
{
	size_t h_left;
	size_t h_right;

	if (!tree)
		return (0);

	h_left = tree->left ? 1 + get_tree_height(tree->left) : 0;
	h_right = tree->right ? 1 + get_tree_height(tree->right) : 0;
	return (h_left > h_right ? h_left : h_right);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid all tree
 * @tree: the root of binary tree
 * Return: 1 if tree is an AVL, else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t h_left;
	size_t h_right;
	size_t mid;

	if (!tree)
		return (0);

	if (!bst(tree))
		return (0);

	h_left = tree->left ? get_tree_height(tree->left) : 0;
	h_right = tree->right ? get_tree_height(tree->right) : 0;

	if (h_left > h_right)
		mid = h_left - h_right;
	else
		mid = h_right - h_left;

	if (mid > 1)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (1);
	else
		return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
