#include <stdio.h>
#include <stdlib.h>
#include "operations.c"
#include "stack_opertaion.c"
#include <assert.h>

int main()
{
    List *testA;
    testA = intialize_list();
    assert(testA->head == NULL);
    assert(testA->tail == NULL);
    assert(testA->count == 0);
    assert(testA->stk->top==NULL);
    assert(insert_at_beg(testA,10));
    assert(testA->stk->top->data.data == 10);
    assert(testA->stk->top->data.operation_type == 11);

    return 0;
}
