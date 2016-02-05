#include "list.h"
#include "stack.h"

#include <stdio.h>
#include <string.h>

#define FILENAME "relations"
#define VERTEX_NUM 14

const char* items[] = { "undershorts", "socks", "compression shorts", "hose", "cup", "pants", "skates", 
			"leg pads", "T-shirt", "chest pad", "sweater", "mask", "catch glove", "blocker" }; 

int adjacency_matrix[VERTEX_NUM][VERTEX_NUM] = {0};
int in_degree[VERTEX_NUM] = {0};
int linear_order[VERTEX_NUM] = {0};

list_node_t *adjacency_list[VERTEX_NUM] = {0};


int read()
{
	FILE *fd = NULL;
	char line[64];

	char *p = NULL, *q = NULL;
	char *from = NULL, *to = NULL;

	fd = fopen(FILENAME, "r");
	if (!fd)
	{
		fprintf(stderr, "Can't open " FILENAME " \n");
		return 1;
	} 
	
	while (fgets(line, 64, fd)) 
	{
		p = q = strchr(line, '>');
		if (!p)
			goto parse_error;

		p -= 2;

		/* getting rid of leading whitespaces */
		while (*p == ' ') 
			p--;

		*++p = 0;	
		from = line;

		q++;
		while (*q == ' ')
			q++;

		to = q;

		q += strlen(q)-1;

		while (*q == ' ' || *q == '\n') 
			q--;
		*++q = 0;

		int i, u = 0, v = 0;
		for (i=0; i<VERTEX_NUM; i++)
		{
			if (strcmp(items[i], from) == 0)
				u = i;
			if (strcmp(items[i], to) == 0) 
			{
				v = i;
				in_degree[i]++;
			}
		}

		list_push_back(&adjacency_list[u], list_node_alloc(v));
		
		//adjacency_matrix[u][v] = 1;


		// fprintf(stdout, "Vertex %s is adjacent to %s\n", items[v], items[u]);
	}

	/* in-degree equals zero for each element on the stack */
	stack_node_t *top = NULL;

	int i,j;
	for (i=0; i<VERTEX_NUM; i++)
		if (0 == in_degree[i])
			push(&top, stack_node_alloc(i));

	i=0, j=0;
	while (top) 
	{
		j = top->data;
		fprintf(stdout, "Processing '%s'\n", items[j]);
		pop(&top);
	
		linear_order[i] = j;
		in_degree[j]--;

		list_node_t *p = adjacency_list[j];
		while (p)
		{
			in_degree[p->data]--;
			if (0 == in_degree[p->data])
				push(&top, stack_node_alloc(p->data));
			p = p->next;
		}
		
		i++;
	}

	for (i=0; i<VERTEX_NUM; i++)
		fprintf(stdout, "%s\n", items[linear_order[i]]);
	

	return 0;

	
parse_error:
	fprintf(stderr, "Parsing error\n");
	
	return 1;

}

int main(int argc, char **argv)
{
	read();
	return 0;
}
