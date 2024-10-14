#include "Box_header.h"

List* initialize_list()
{
    List *my_list;
    my_list = (List*)malloc(sizeof(List));
    if(NULL == my_list)
        return MEM_ALLOC_FAILED;
    my_list->head = NULL;
    my_list->count = 0;
    return my_list;
}

float calculate_volume(Box box)
{
    return box.breadth*box.height*box.length;
}

int is_unique_shape(List *my_list, Box new_box)
{
    Node *temp;
    for(temp = my_list->head; temp != NULL; temp = temp->ptr)
    {
        if(temp->data.breadth == new_box.breadth || temp->data.height == new_box.height || temp->data.length == new_box.length)
            return NOT_UNIQUE;
    }
    return UNIQUE;
}

Node* get_node(Box new_box)
{
    Node *new_node;
    new_node = (Node*)malloc(sizeof(Node));

    if(NULL == new_node)
        return MEM_ALLOC_FAILED;

    new_box.volume = calculate_volume(new_box);
    new_node->data = new_box;
    new_node->ptr = NULL;

    return new_node;
}
int insert_at_beg(List *my_list, Box new_box)
{
    Node *new_node;
    if(is_unique_shape(my_list, new_box))
    {
        new_node = get_node(new_box);

        if(NULL == new_node)
            return FAILED;

        if(my_list->count == 0)
        {
            my_list->head = new_node;
        }
        else
        {
            new_node->ptr = my_list->head;
            my_list->head = new_node;
        }
        my_list->count++;
        return SUCCESS;
    }
    else
        return FAILED;
}
int is_same_volume(List *my_list)
{
    Node *temp, *prev;

    for(prev = my_list->head, temp = my_list->head->ptr; temp != NULL; prev = temp,temp = temp->ptr)
    {
        if(prev->data.volume == temp->data.volume)
            return SAME_VOLUME;
    }
    return NO_VOLUME_IS_SAME;
}
Stack initialize_stack(int size)
{
    Stack my_stack;

    my_stack->top = -1;
    my_stack->size = size>0 && size<MAX_SIZE ? size: MAX_SIZE;
}

int push(Stack my_stack, Box data)
{
    if(my_stack->top<my_stack->size-1)
    {
        my_stack->data[++my_stack->top] = data;
    }
    else{
        return STACK_IS_FULL;
    }
    return SUCCESS;
}

int check_if_volume_greater_than_1000(List *my_list, Stack my_stack)
{
    Node *temp;

    for(temp = my_list->head; temp != NULL; temp = temp->ptr)
    {
        if(temp->data.volume>1000)
        {
            push(my_stack, temp->data);
            return GREATER_VOLUME;
        }
    }
    return LESS_VOLUME;
}

