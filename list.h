typedef struct node_t {
	int data;
	struct node_t *next;
	struct node_t *prev; 
} node_t;
 
typedef struct {
	node_t *head;
	node_t *tail;
} list_t;

node_t* node_new(int data);
void node_free(node_t *node);

void list_push_back(list_t *list, node_t *node);
void list_push_front(list_t *list, node_t *node);

node_t* list_pop_back(list_t *list);
node_t* list_pop_front(list_t *list);

void list_print(list_t *list);

list_t* list_new(void);
void list_init(list_t *list);
void list_free(list_t *list);

void list_cleanse(list_t *list);
