#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * add_nodeint_head - adds a new node at the head of a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @n: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *add_nodeint_head(listint_t *head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = head;
	head = new;

	return (new);
}
/**
 * clone - clone a list
 * @head: pointer to pointer of first node of listint_t list
 * Return: address of the clone head
 */
listint_t *clone(listint_t **head)
{
	listint_t *new;
	listint_t *current;

	current = *head;
	new = NULL;

	while (current != NULL)
	{
		new = add_nodeint_head(new, current->n);
		current = current->next;
	}

	return (new);
}
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 *
 *
 */
int is_palindrome(listint_t **head)
{
	listint_t *new;
	listint_t *current;

	current = *head;
	if (current == NULL)
		return (1);
	new = clone(head);
	while (current != NULL)
	{
		if (new->n != current->n)
			return (0);
		current = current->next;
		new = new->next;
	}
	return (1);
}

