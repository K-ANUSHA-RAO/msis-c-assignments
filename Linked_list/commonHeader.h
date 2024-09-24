#ifndef COMMONHEADER_H_INCLUDED
#define COMMONHEADER_H_INCLUDED
#include "stack.h"
#define MEM_ALLOC_FAILED 0
#define SUCCESS 1
#define OPERATION_FAILED NULL
#define LIST_ALLOC_FAIL NULL
#define NODE_ALLOC_FAIL NULL
#define FAIL 0
#define FOUND 1
#define NOT_FOUND 0
#define LIST_EMPTY 0
#define LIST_NOT_INIT -1

struct _node_
{
    int data;
    struct _node_ *ptr;
};
typedef struct _node_ Node;

struct _linked_list_
{
    Node *head;
    Node *tail;
    StackList *stk;
    int count;
};
typedef struct _linked_list_ List;

List* intialize_list();
int insert_at_beg(List*, int);
int insert_at_end(List*, int);
List* merge_listA_and_listB(List*, List*);

int insert_after_element(List *, int, int element);
int insert_and_sort(List *, int);
int delete_at_beg(List *);
int delete_at_end(List *);
int delete_element(List *, int element);

#endif // COMMONHEADER_H_INCLUDED
