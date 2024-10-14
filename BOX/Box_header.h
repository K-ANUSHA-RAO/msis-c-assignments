#ifndef BOX_HEADER_H_INCLUDED
#define BOX_HEADER_H_INCLUDED

#define MAX_SIZE 20
#define MEM_ALLOC_FAILED NULL
#define FAILED 0
#define SUCCESS 1
#define NOT_UNIQUE 0
#define UNIQUE 1
#define NO_VOLUME_IS_SAME 0
#define SAME_VOLUME 1
#define GREATER_VOLUME 1
#define LESS_VOLUME 0
#define STACK_IS_FULL 0

struct box_measure
{
    float length, breadth, height;
    float volume;
};
typedef struct box_measure Box;

struct node
{
    Box data;
    struct node *ptr;
};
typedef struct node Node;

struct linked_list
{
    Node *head;
    int count;
};
typedef struct linked_list List;

struct stack
{
    Box data[MAX_SIZE];
    int top;
    int size;
};
typedef struct stack *Stack;

List* initialize_list();
int insert_at_beg(List *,Box);
int is_unique_shape(List *, Box);
int is_same_volume(List *);
Stack initialize_stack(int size);
int push(Stack , Box);
int check_if_volume_greater_than_1000(List *, Stack my_stack);
#endif // BOX_HEADER_H_INCLUDED
