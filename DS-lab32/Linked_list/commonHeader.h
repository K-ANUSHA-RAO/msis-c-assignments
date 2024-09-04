#ifndef COMMONHEADER_H_INCLUDED
#define COMMONHEADER_H_INCLUDED
#define MEM_ALLOC_FAILED 0
#define SUCCESS 1
#define OPERATION_FAILED NULL

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
    int count;
};
typedef struct _linked_list_ List;

List* intialize_list();
int insert_at_beg(List*, int);
int insert_at_end(List*, int);
List* merge_listA_and_listB(List*, List*);
#endif // COMMONHEADER_H_INCLUDED
