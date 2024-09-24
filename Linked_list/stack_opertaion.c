#include "stack.h"
#include "commonHeader.h"

StackList* initialise_stack()
{
    StackList *my_stack_list;

    my_stack_list = (StackList*)malloc(sizeof(StackList));

    if(NULL == my_stack_list)
        return MEM_ALLOC_FAILED;

    my_stack_list->count = 0;
    my_stack_list->top = NULL;

    return my_stack_list;

}
Stack* get_stack_data(OpData data)
{
    Stack *new_node;
    new_node = (Stack*)malloc(sizeof(Stack));
    if(NULL == new_node)return MEM_ALLOC_FAILED;
    new_node->data = data;
    new_node->ptr = NULL;
    return new_node;
}
int stack_push(StackList *stk, OpData data)
{
    Stack *new_node;
    new_node = get_stack_data(data);
    if(NULL == new_node)return MEM_ALLOC_FAILED;

    if(stk->count == 0)
    {
        stk->top = new_node;
    }
    else{
        new_node->ptr = stk->top;
        stk->top = new_node;
    }
    stk->count++;
    return SUCCESS;
}
StackList stack_pop(Stack *stk, int data);
int undo(Stack *stk);
