#include "list.h"

#include <stdio.h>
#include <stdlib.h>

list_node_t* list_node_alloc(int data)
{
	list_node_t *node = malloc(sizeof(list_node_t));

	if (!node)
		return NULL;

	node->data = data;
	node->next = NULL;
}

void list_node_free(list_node_t **head_ref)
{
	list_node_t *p = *head_ref;
	list_node_t *tmp = NULL;

	if (!p) 
		return;

	while(p->next)
	{
		tmp = p;
		p = p->next;
		free(tmp);	
	}
}

void list_push_back(list_node_t **head_ref, list_node_t *node)
{
	list_node_t *p = *head_ref;

	node->next = NULL;

	/* first node */
	if (!p)
	{
		*head_ref = node;
		return;
	}

	while (p->next)
		p = p->next;

	p->next = node;
}

void list_push_front(list_node_t **head_ref, list_node_t *node)
{
	list_node_t *p = *head_ref;

	node->next = p;
	*head_ref = node;
}

//int main(int argc, char **argv)
//{
//	list_node_t *head = NULL;
//	
//	list_push_back(&head, list_node_alloc(2));
//	list_push_back(&head, list_node_alloc(5));
//	list_push_back(&head, list_node_alloc(7));
//	list_push_back(&head, list_node_alloc(11));
//
//	list_node_t *p = head;
//	while (p)
//	{
//		fprintf(stdout, "%d\n", p->data);
//		p = p->next;
//	}
//
//	list_node_free(&head);
//
//	return 0;
//}
