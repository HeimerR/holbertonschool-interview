#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a node in the binary tree (right)
 * @parent: pointer to a parent node
 * @value: number value in the node
 * Return: pointer to the new node inserted
**/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp, *node;

	if (!parent)
		return (NULL);
	tmp = parent->right;
	node = binary_tree_node(parent, value);
	parent->right = node;
	if (tmp != NULL)
	{
		node->right = tmp;
		tmp->parent = node;
	}
	return (node);
}
/**
 * binary_tree_insert_left - inserts a node in the binary tree (left)
 * @parent: pointer to a parent node
 * @value: number value in the node inserted
 * Return: pointer to the new node
**/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp, *node;

	if (!parent)
		return (NULL);
	tmp = parent->left;
	node = binary_tree_node(parent, value);
	parent->left = node;
	if (tmp != NULL)
	{
		node->left = tmp;
		tmp->parent = node;
	}
	return (node);
}
/**
 * height - mesures height
 * @tree: pointer to the node
 * Return: height
 **/
int height(binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	right = height(tree->right) + 1;
	left = height(tree->left) + 1;
	if (left > right)
		return (left);
	else
		return (right);
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect (complete&BF=1)
 * @tree: pointer to the node
 * Return: 1 if it is perfect 0 otherwise
 **/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if ((!tree->left && !tree->right) || ((binary_tree_is_perfect(tree->left)
	    == 1 && binary_tree_is_perfect(tree->right) == 1) && height(tree->left)
	    == height(tree->right)))
		return (1);
	return (0);
}
/**
 * binary_tree_sibling - which is the sibling?
 * @node: pointer to the node
 * Return: pointer to sibling
 **/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (!node->parent->left || !node->parent->right)
		return (NULL);
	if (node->n == node->parent->left->n)
		return (node->parent->right);
	else
		return (node->parent->left);
}
/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to node to verify is a leaf
 * Return: 1 if node is a leaf, otherwise 0
 **/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!node->left && !node->right)
		return (1);
	else
		return (0);
}
/**
 * swaps - swaps number to be a heap
 * @node: pointer to the node input
 * Return: pointer to node output
 **/
heap_t *swaps(heap_t *node)
{
	int aux;

	while (node->parent && node->parent->n < node->n)
	{
		aux = node->n;
		node->n = node->parent->n;
		node->parent->n = aux;
		node = node->parent;
	}
	return (node);
}
/**
 * preorder - goes through a binary tree using pre-order traversal
 * @last_node: double pointer to find the last node
 * @tree: pointer to the root
 * @level: level to print
 * @ref: reference to start
 * @flag: only work for first match
 * Return: no return
 **/
void preorder(heap_t *tree, int level, int ref, heap_t **last_node, int *flag)
{
	if (!tree)
		return;
	if (level == ref)
	{
		last_node[0] = tree;
	}
	if (level - 1 == ref && binary_tree_is_leaf(tree) == 1 && *flag == 0)
	{
		last_node[1] = tree;
		*flag = 1;
	}
	if (tree->left)
		preorder(tree->left, level, ref + 1, last_node, flag);
	if (tree->right)
		preorder(tree->right, level, ref + 1, last_node, flag);
}
/**
 * levelorder - traverses in zig-zag
 * @tree: pointer to the root
 * @last_node: last node in the tree
 * Return: no return
 **/
void levelorder(heap_t *tree, heap_t **last_node)
{
	int h, i, flag = 0;

	if (!tree)
		return;
	h = height(tree);
	for (i = 0; i <= h; i++)
	{
		preorder(tree, i, 0, last_node, &flag);
	}
}
/**
 * heap_insert - nserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: the value store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *first_row_node, **last_node, *insert_node, *aux;

	if (!root)
		return (NULL);
	tree = *root;
	if (!tree)
	{
		*root = binary_tree_node(tree, value);
		return (*root);
	}
	aux = *root;
	first_row_node = *root;
	last_node = malloc(sizeof(heap_t *) * 2);
	last_node[0] = *root;
	last_node[1] = *root;
	levelorder(tree, last_node);
	while (first_row_node->left)
		first_row_node = first_row_node->left;
	if (first_row_node == *last_node && first_row_node->parent == NULL)
	{
		insert_node = binary_tree_insert_left(first_row_node, value);
		insert_node = swaps(insert_node);
		free(last_node);
		*root = aux;
		return (insert_node);
	}
	*root = aux;
	if (binary_tree_sibling(*last_node))
	{
		if (!binary_tree_is_perfect(*root))
			insert_node = binary_tree_insert_left(last_node[1], value);
		else
			insert_node = binary_tree_insert_left(first_row_node, value);
	}
	else
		insert_node = binary_tree_insert_right(last_node[0]->parent, value);
	insert_node = swaps(insert_node);
	free(last_node);
	*root = aux;
	return (insert_node);
}
