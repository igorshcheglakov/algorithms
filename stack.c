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

void stack_node_free(stack_node_t **top_ref)
{
	stack_node_t *p = *top_ref;
	stack_node_t *tmp = NULL;

	if (!p)
		return;

	while (p->next)
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}
}

void pop(stack_node_t **head_ref)
{
	stack_node_t *node = *head_ref;

	if (node)
	{
		*head_ref = node->next;
		free(node);
	}
}

void push(stack_node_t **head_ref, stack_node_t *new_node)
{
	stack_node_t *head = *head_ref;

	new_node->next = head;
	*head_ref = new_node; 
}

//int main(int argc, char **argv)
//{
//	stack_node_t *top = NULL;
//	
//	push(&top, stack_node_alloc(3));
//	push(&top, stack_node_alloc(5));
//	push(&top, stack_node_alloc(7));
//	push(&top, stack_node_alloc(11));
//	
//	pop(&top);
//
//	while (top) 
//	{
//		fprintf(stdout, "%d\n", top->data);
//		top = top->next;
//	}
//
//	stack_node_free(&top);
//
//	return 0;
//}
