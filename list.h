typedef struct list_node_t {
	int data;
	struct list_node_t *next;
} list_node_t;
 
list_node_t* list_node_alloc(int data);
void list_node_free(list_node_t **head_ref);

void list_push_back(list_node_t **head_ref, list_node_t *node);
void list_push_front(list_node_t **head_ref, list_node_t *node);
