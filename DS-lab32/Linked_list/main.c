#include <stdio.h>
#include <stdlib.h>
#include "operations.c"
#include <assert.h>

int main()
{
    List *testA, *testB , *testC;
    testA = intialize_list();
    testB = intialize_list();
    assert(testA->head == NULL);
    assert(testA->tail == NULL);
    assert(testA->count == 0);

    assert(insert_at_end(testA,10));
    assert(insert_at_end(testA,20));
    assert(insert_at_end(testA,30));

    assert(insert_at_end(testB,15));
    assert(insert_at_end(testB,30));
    assert(insert_at_end(testB,90));

    testC = merge_listA_and_listB(testA,testB);

    assert(testC->head->data == 10);
    assert(testC->head->ptr->data == 15);
    assert(testC->head->ptr->ptr->data == 20);
    //assert(testC->head->ptr->data==15);
    printf("%d ", testC->head->data);
    printf("%d ", testC->head->ptr->data);
    printf("%d ", testC->head->ptr->ptr->data);
    printf("%d ", testC->head->ptr->ptr->ptr->data);
    printf("%d ", testC->head->ptr->ptr->ptr->ptr->data);
    printf("%d ", testC->head->ptr->ptr->ptr->ptr->ptr->data);
    assert(testC->count == 6);
    return 0;
}
