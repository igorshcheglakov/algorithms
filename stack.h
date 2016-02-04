typedef struct stack_node_t {
	int data;
	struct stack_node_t *next;
} stack_node_t;

stack_node_t* stack_node_alloc(int data);
void stack_node_free(stack_node_t *node);

void pop(stack_node_t **head_ref);
void push(stack_node_t **head_ref, stack_node_t *new_node);
