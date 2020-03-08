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
	int len = 0, i;
	listint_t *h;
	int aux[1000000];

	h = *head;
	if (!h)
		return (1);
	while (h)
	{
		aux[len] = h->n;
		h = h->next;
		len++;
	}
	for (i = 0; i < len; i++)
	{
		if (aux[i] != aux[len - 1 - i])
			return (0);
	}
	return (1);
}
