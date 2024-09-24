#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define INSERT_AT_BEG 11
#define INSERT_AT_END 12
#define DELETE_AT_BEG 13
#define DELETE_AT_END 14

struct _op_data_
{
    int data;
    int operation_type;
};
typedef struct _op_data_ OpData;

struct _stack_
{
    OpData data;
    struct _stack_ *ptr;
};
typedef struct _stack_ Stack;

struct _stack_list
{
    Stack *top;
    int count;
};
typedef struct _stack_list StackList;

StackList* initialise_stack();
int stack_push(StackList *stk, OpData data);
StackList stack_pop(Stack *stk, int data);
int undo(Stack *stk);
#endif // STACK_H_INCLUDED
