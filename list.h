typedef struct list_node_t {
	int data;
	struct list_node_t *next;
	struct list_node_t *prev; 
} list_node_t;
 
typedef struct {
	list_node_t *head;
	list_node_t *tail;
} list_t;

list_node_t* list_node_alloc(int data);
void list_node_free(list_node_t *node);

void list_push_back(list_t *list, list_node_t *node);
void list_push_front(list_t *list, list_node_t *node);

list_node_t* list_pop_back(list_t *list);
list_node_t* list_pop_front(list_t *list);

void list_print(list_t *list);

list_t* list_new(void);
void list_init(list_t *list);
void list_free(list_t *list);

void list_cleanse(list_t *list);
