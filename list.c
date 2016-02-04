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
	node->prev = NULL;
}

void list_node_free(list_node_t *node)
{
	if (node)
		free(node);
}

static void push_first(list_t *list, list_node_t *node)
{
	node->next = NULL;
	node->prev = NULL;

	list->head = node;
	list->tail = node; 
}

list_t* list_new(void)
{
	list_t *list = malloc(sizeof(list_t));
	
	if (!list)
		return NULL;
	
	list_init(list);

	return list; 
}

void list_init(list_t *list)
{
	list->head = NULL;
	list->tail = NULL;
}

void list_free(list_t *list)
{
	list_cleanse(list);
	free(list);	
}

void list_cleanse(list_t *list)
{
	list_node_t *p = list->head;
	while (p) 
	{
		list_node_t *tmp = p;
		p = p->next;
		free(tmp);
	}

	list->head = NULL;
	list->tail = NULL;
}

void list_push_back(list_t *list, list_node_t *node)
{
	if (!list->head)
	{	
		push_first(list, node);
	}
	else
	{
		node->next = NULL;
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	} 
}

void list_push_front(list_t *list, list_node_t *node)
{
	if (!list->head)
	{
		push_first(list, node);
	}
	else
	{
		node->prev = NULL;
		list->head->prev = node;
		node->next = list->head;
		list->head = node; 
	} 
}

list_node_t* list_pop_back(list_t *list)
{
	list_node_t *back_node = list->tail;
	if (!back_node)
		return NULL;

	/* check if this is the only element left in the list */
	if (!back_node->prev)
	{
		list->head = NULL;
		list->tail = NULL;
		return back_node;
	}

	back_node->prev->next = NULL;
	list->tail = back_node->prev; 
	back_node->prev = NULL;
	back_node->next = NULL;

	return back_node;
}

list_node_t* list_pop_front(list_t *list)
{
	list_node_t *front_node = list->head;
	if (!front_node)
		return NULL;

	if (!front_node->next)
	{
		list->head = NULL;
		list->tail = NULL;
		return front_node;
	}

	front_node->next->prev = NULL;
	list->head = front_node->next;
	front_node->prev = NULL;
	front_node->next = NULL;

	return front_node;
}

void list_print(list_t *list)
{
	list_node_t *p = list->head;
	while (p)
	{
		fprintf(stdout, "%d\n", p->data);
		p = p->next;
	} 
}

//int main(int argc, char **argv)
//{
//
//	list_t *list = list_new();	
//
//	list_push_back(list, list_node_alloc(2));
//	list_push_back(list, list_node_alloc(5));
//	list_push_back(list, list_node_alloc(7));
//	list_push_back(list, list_node_alloc(11));
//
//	list_node_t *back = list_pop_back(list);
//	list_node_t *front = list_pop_front(list);
//	
//	list_node_free(back);
//	list_node_free(front);
//
//	list_print(list);
//	list_free(list);
//
//	return 0;
//}
