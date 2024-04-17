#include "binary_trees.h"

/**
 * binary_tree_node - Declares and initializes a node for a binary tree
 *
 * @parent: The parent to the newly created node
 * @value: The data the new node holds
 *
 * Return: A pointer to the new "binary_tree_t" node, or NULL if malloc fails
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	new = malloc(sizeof(binary_tree_t));

	if (!new)
	{
		return (NULL);
	}

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
