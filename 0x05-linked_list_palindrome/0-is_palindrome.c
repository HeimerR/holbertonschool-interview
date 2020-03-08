#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 *
 *
 */
int is_palindrome(listint_t **head)
{
	listint_t *current;
	int i = 0, j;
	int array[5000];

	current = *head;
	if (current == NULL)
		return (1);
	while (current != NULL)
	{
		array[i++] = current->n;
		current = current->next;
	}
	for (j = 0; j <= (i / 2) + 1; j++)
	{
		if (array[j] != array[--i])
			return (0);
	}
	return (1);
}
