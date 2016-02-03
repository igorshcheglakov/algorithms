#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node_t {
	int data;
	struct stack_node_t *next;
} stack_node_t;

stack_node_t* node_new(int data)
{
	stack_node_t *node = malloc(sizeof(stack_node_t));

	if (!node)
		return NULL;

	node->data = data;
	node->next = NULL;

	return node;
}

void node_free(stack_node_t *node)
{
	if (node)
		free(node);
}

stack_node_t* pop(stack_node_t **head_ref)
{
	stack_node_t *head = *head_ref;

	if (!head)
		return NULL;

	if (!head->next) {
		*head_ref = NULL;
		return head;
	}
	
	*head_ref = head->next;

	head->next = NULL;

	return head;
}

void push(stack_node_t **head_ref, stack_node_t *new_node)
{
	stack_node_t *head = *head_ref;

	if (!head) 
	{	new_node->next = NULL;
		*head_ref = new_node;
	}
	else
	{
		new_node->next = head;
		*head_ref = new_node; 
	} 
}

void stack_print(const stack_node_t *head)
{
	const stack_node_t *p = head;

	while (p) 
	{
		fprintf(stdout, "%d\n", p->data);
		p = p->next;
	}
}

int main(int argc, char **argv)
{
	stack_node_t *head = NULL;
	
	push(&head, node_new(3));
	push(&head, node_new(5));
	push(&head, node_new(7));
	push(&head, node_new(11));


	while (head)
	{
		stack_node_t *p = pop(&head);
		fprintf(stdout, "%d\n", p->data);
		node_free(p);
	}	

	return 0;
}
