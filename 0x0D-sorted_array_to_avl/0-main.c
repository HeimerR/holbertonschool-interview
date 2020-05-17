#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Size of the array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i)
		printf("(%03d)", array[i]);
	printf("\n");
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	avl_t *tree;
	avl_t *tree2;
	int array[] = {
		1, 2, 20, 21, 22, 32, 34, 47, 62, 68,
		79, 84, 87, 91, 95, 98
	};
	int array2[] = {1, 2, 3, 4};
	size_t n = sizeof(array) / sizeof(array[0]);
	size_t n2 = sizeof(array2) / sizeof(array2[0]);

	tree = sorted_array_to_avl(array, n);
	tree2 = sorted_array_to_avl(array2, n2);
	if (!tree)
		return (1);
	print_array(array, n);
	binary_tree_print(tree);
	tree = sorted_array_to_avl(array2, n2);
	if (!tree2)
		return (1);
	print_array(array2, n2);
	binary_tree_print(tree2);
	return (0);
}
