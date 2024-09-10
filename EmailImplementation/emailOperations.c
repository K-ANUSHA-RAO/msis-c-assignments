#include "emailHeader.h";
#include <string.h>

List* initialize_List()
{
    List *my_list;

    my_list = (List *)malloc(sizeof(List));

    if(my_list == NULL) return MEM_ALLOC_FAILED;

    my_list->count = 0;
    my_list->head = my_list->tail = NULL;

    return my_list;
}

Email* get_email(Mail_Data data)
{
    Email *new_email;

    new_email = (Email *)malloc(sizeof(Email));

    if(NULL == new_email)return MEM_ALLOC_FAILED;

    new_email->mail_data = data;
    new_email->ptr = NULL;

}
int insert_at_beg(List *my_list, Mail_Data data)
{
    Email *new_email;

    new_email = get_email(data);

    if(NULL == new_email)return MEM_ALLOC_FAILED;

    if(my_list->count == 0)
    {
        my_list->head = my_list->tail = new_email;
    }
    else
    {
        new_email->ptr = my_list->head;
        my_list->head = new_email;
    }
    my_list->count++;
    return SUCCESS;
}
int archive_email(List *my_list, char *sender_name)
{
    Email *temp;

    if(my_list->count == 0) return EMPTY_LIST;

    if(strcmp(my_list->head->mail_data.sender_name, sender_name)==0)
        my_list->head->mail_data.mail_status = ARCHIVE;

    if(strcmp(my_list->tail->mail_data.sender_name,sender_name)==0)
        my_list->tail->mail_data.mail_status = ARCHIVE;

    for(temp = my_list->head; temp!= NULL && (strcmp(temp->ptr->mail_data.sender_name,sender_name)!=0); temp=temp->ptr);
    if(temp == NULL) return SENDER_NOT_FOUND;

    temp->mail_data.mail_status = ARCHIVE;
    return SUCCESS;

}
int restore_email(List *my_list, char *sender_name)
{
    Email *temp;

    if(my_list->count == 0) return EMPTY_LIST;

    if(strcmp(my_list->head->mail_data.sender_name, sender_name)==0)
        my_list->head->mail_data.mail_status = INBOX;

    if(strcmp(my_list->tail->mail_data.sender_name,sender_name)==0)
        my_list->tail->mail_data.mail_status = INBOX;

    for(temp = my_list->head; temp!= NULL && (strcmp(temp->ptr->mail_data.sender_name,sender_name)!=0); temp=temp->ptr);
    if(temp == NULL) return SENDER_NOT_FOUND;

    temp->mail_data.mail_status = INBOX;
    return SUCCESS;

}
