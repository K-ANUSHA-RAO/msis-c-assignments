#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "box_operations.c"

int main()
{
    List *test_list;
    test_list = initialize_list();
    assert(test_list->count == 0);
    assert(test_list->head == NULL);

    //test values for box
    Box box1 = {/*length*/ 10, /*breadth*/ 2, /*height*/1, /*volume*/0};
    Box box2 = {/*length*/ 1, /*breadth*/ 10, /*height*/2, /*volume*/0};
    Box box3 = {/*length*/ 11, /*breadth*/ 3, /*height*/10, /*volume*/0};
    Box box4 = {/*length*/ 5, /*breadth*/ 30, /*height*/6, /*volume*/0};
    Box box5 = {/*length*/ 3, /*breadth*/ 1, /*height*/5, /*volume*/0};
    Box box6 = {/*length*/ 4, /*breadth*/ 5, /*height*/12, /*volume*/0};
    Box box7 = {/*length*/ 12, /*breadth*/ 8, /*height*/20, /*volume*/0};
    Box box8 = {/*length*/ 8, /*breadth*/ 20, /*height*/4, /*volume*/0};
    Box box9 = {/*length*/ 30, /*breadth*/ 80, /*height*/40, /*volume*/0};
    Box box10 = {/*length*/ 80, /*breadth*/ 40, /*height*/30, /*volume*/0};

    insert_at_beg(test_list, box1);
    assert(test_list->count==1);
    assert(test_list->head->data.volume == 20);

    assert(insert_at_beg(test_list, box2)== 1);
    assert(insert_at_beg(test_list, box3)== 1);
    assert(insert_at_beg(test_list, box4)== 1);
    assert(insert_at_beg(test_list, box5)== 1);
    assert(insert_at_beg(test_list, box6)== 1);
    assert(insert_at_beg(test_list, box7)== 1);
    assert(insert_at_beg(test_list, box8)== 1);
    assert(insert_at_beg(test_list, box9)== 1);
    assert(insert_at_beg(test_list, box10)== 1);

    assert(test_list->count==10);


    assert(is_same_volume(test_list)== 1);


    //check_if_volume_greater_than_1000

    Stack test_stack;

    test_stack = initialize_stack(10);
    assert(test_stack->top==-1);
    assert(check_if_volume_greater_than_1000(test_list,test_stack)==1);
    assert(test_stack->top>-1);
    return 0;
}
