#include "commonHeader.h"

List* intialize_list()
{
    List *my_list;
    my_list = (List*)malloc(sizeof(List));
    if(NULL == my_list) return MEM_ALLOC_FAILED;
    my_list->head = my_list->tail = NULL;
    my_list->count = 0;
    return my_list;
}
Node* get_node(int data)
{
    Node *new_node;
    new_node = (Node*)malloc(sizeof(Node));
    if(NULL == new_node)return MEM_ALLOC_FAILED;
    new_node->data = data;
    new_node->ptr = NULL;
    return new_node;
}
int insert_at_beg(List *my_list, int data)
{
    Node *new_node;
    new_node = get_node(data);

    if(NULL == new_node)return MEM_ALLOC_FAILED;

    if(my_list->count == 0)
    {
        my_list->head = my_list->tail = new_node;
    }
    else{
        new_node->ptr = my_list->head;
        my_list->head = new_node;
    }
    my_list->count++;
    return SUCCESS;
}

int insert_at_end(List *my_list, int data)
{
    Node *new_node;

    new_node = get_node(data);

    if( NULL == new_node) return MEM_ALLOC_FAILED;

    if(0 == my_list->count)
        my_list->head =my_list->tail = new_node;
    else
    {
        my_list->tail->ptr = new_node;
        my_list->tail = new_node;
    }
    my_list->count++;

    return SUCCESS;
}

List* merge_listA_and_listB(List *my_listA, List *my_listB)
{
    List *my_listC;
    Node *tempA, *tempB;
    if(NULL == my_listA || NULL == my_listB) return OPERATION_FAILED;

    my_listC = intialize_list();

    if(NULL == my_listC) return MEM_ALLOC_FAILED;

    tempA = my_listA->head;
    tempB = my_listB->head;

    while(tempA != NULL && tempB != NULL)
    //for(tempA = my_listA->head, tempB = my_listB->head; tempA != NULL && tempB != NULL; tempA = tempA->ptr, tempB = tempB->ptr)
    {
        if(tempA->data <= tempB->data) {
            insert_at_end(my_listC, tempA->data);
            tempA = tempA->ptr;
        }
       else{
            insert_at_end(my_listC, tempB->data);
            tempB = tempB->ptr;
        }
    }
    if(tempA == NULL){
            while(tempB != NULL){
                insert_at_end(my_listC,tempB->data);
                tempB = tempB->ptr;
            }
        }
        else{
            while(tempA != NULL){
                insert_at_end(my_listC,tempA->data);
                tempA = tempA->ptr;
            }
        }

    return my_listC;
}
