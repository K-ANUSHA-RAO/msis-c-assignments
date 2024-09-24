#include "commonHeader.h"
#include "stack.h"

List* intialize_list()
{
    List *my_list;
    StackList *my_stack;
    //my_stack = (StackList*)malloc(sizeof(StackList));
    my_list = (List*)malloc(sizeof(List));
    if(NULL == my_list) return MEM_ALLOC_FAILED;
    my_list->head = my_list->tail = NULL;
    my_list->count = 0;
    my_stack = initialise_stack();
    my_list->stk = my_stack;
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
    OpData stack_data;

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
    stack_data.data = data;
    stack_data.operation_type = INSERT_AT_BEG;
    stack_push(my_list->stk, stack_data);
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
int insert_after_element(List *my_list, int data, int element)
{
    Node *new_node, *temp;

    if(my_list == NULL || my_list->count == 0) return FAIL;

    if(my_list->tail->data == element)
        return insert_at_end(my_list, data);

    for(temp = my_list->head; \
        temp != my_list->tail && temp->data != element; \
        temp = temp->ptr);

    if(temp == my_list->tail) return FAIL;

    new_node = get_node(data);

    new_node->ptr = temp->ptr;
    temp->ptr = new_node;
    my_list->count++;

    return SUCCESS;

}


Node *get_element_address(List *my_list, int data)
{
    Node *temp;

    for(temp = my_list->head;\
      temp != my_list->tail && temp->ptr->data < data;\
      temp = temp->ptr);

    return temp;
}
void connect_node(Node *new_node,Node *temp)
{
    new_node->ptr = temp->ptr;
    temp->ptr = new_node;
}

int insert_and_sort(List *my_list, int data)
{
    Node *temp, *new_node;

    if(my_list == NULL) return FAIL;

    if(my_list->count == 0 || my_list->head->data >= data)
        return insert_at_beg(my_list, data);
    if(my_list->tail->data <= data)
        return insert_at_end(my_list, data);

    //return the address of node after which new data has to be inserted
    temp = get_element_address(my_list, data);

    //if element not found
    if(temp == my_list->tail) return NOT_FOUND;

    new_node = get_node(data);//create a new node
    //function to insert new_node after a element. Same function can
    // reused in insert_after_element
    connect_node(new_node, temp);
    my_list->count++;

    return SUCCESS;
}
int delete_at_beg(List *my_list)
{
    Node * temp = my_list->head;
    //if list is empty return LIST_EMPTY
    if(my_list->count == 0)
        return LIST_EMPTY;

    //check if list has one node then update head and tail to NULL
    if(my_list->count == 1)
        my_list->head = my_list->tail = NULL;
    //move the head to next node and free previous head
    else
        my_list->head = my_list->head->ptr;

     free(temp);
    //decrement the count
     my_list->count--;
    //return SUCCESS
     return SUCCESS;
}


int delete_at_end(List *my_list)
{
    Node *temp = my_list->head;
    // if list is empty
    if(my_list->count == 0) return LIST_EMPTY;
    //if list has one element
    if(my_list->count == 1){
        my_list->head = my_list->tail = NULL;
        free(temp);
    }
    // traverse till last but one node
    else{
        for(; temp->ptr != my_list->tail; temp = temp->ptr);
        free(temp->ptr);
        my_list->tail = temp;
        my_list->tail->ptr = NULL;
    }
    my_list->count--;

    return SUCCESS;

}
int delete_element(List *my_list, int element)
{
    Node *temp, *prev;

    //check if list is empty
    if(my_list->count == 0) return LIST_EMPTY;

    // check element is at head
    if(my_list->head->data == element)
        return delete_at_beg(my_list);

    //check if element is at tail
    if(my_list->tail->data == element)
        return delete_at_end(my_list);

    //search for element
    for(prev= my_list->head, temp= my_list->head->ptr;\
        temp != my_list->tail && temp->data != element;\
        prev = temp, temp = temp->ptr);

    //check if element found
    if(temp == my_list->tail) return NOT_FOUND;

    prev->ptr = temp->ptr;
    free(temp);
    my_list->count--;

    return SUCCESS;
}
