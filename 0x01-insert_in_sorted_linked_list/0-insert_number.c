#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
* listint_t *insert_node - insert a node in a sorted linked list
* @head: double pointer - head of the list
* @number: numner to insert
* Return: pointer to new node or NULL if fails
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	current = *head;
	if (current == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		while (current->next != NULL && current->next->n < number)
			current = current->next;
		if (current->n > number)
		{
			*head = new;
			new->next = current;
		}
		else
		{
			new->next = current->next;
			current->next = new;
		}
	}
	return (new);
}
