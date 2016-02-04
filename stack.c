#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

stack_node_t* stack_node_alloc(int data)
{
	stack_node_t *node = malloc(sizeof(stack_node_t));

	if (!node)
		return NULL;

	node->data = data;
	node->next = NULL;

	return node;
}

void stack_node_free(stack_node_t *node)
{
	if (node)
		free(node);
}

void pop(stack_node_t **head_ref)
{
	stack_node_t *node = *head_ref;

	if (node)
	{
		*head_ref = node->next;
		stack_node_free(node);
	}
}

void push(stack_node_t **head_ref, stack_node_t *new_node)
{
	stack_node_t *head = *head_ref;

	new_node->next = head;
	*head_ref = new_node; 
}

int _main(int argc, char **argv)
{
	stack_node_t *head = NULL;
	
	push(&head, stack_node_alloc(3));
	push(&head, stack_node_alloc(5));
	push(&head, stack_node_alloc(7));
	push(&head, stack_node_alloc(11));
	
	pop(&head);

	while (head)
	{
		fprintf(stdout, "%d\n", head->data);
		pop(&head);
	}	

	return 0;
}
