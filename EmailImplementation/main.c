#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "emailOperations.c"

int main()
{
    List *my_list;
    Mail_Data my_email;
    my_list = initialize_List();

    assert(my_list->count == 0);

    strcpy(my_email.receiver_name, "Anusha");
    strcpy(my_email.sender_name, "Anujna");
    strcpy(my_email.subject, "DS LAB");
    my_email.mail_status = 1;

    insert_at_beg(my_list, my_email);

    assert(strcmp(my_list->head->mail_data.sender_name,"Anujna")==0);

    archive_email(my_list,"Anujna");
    assert(my_list->head->mail_data.mail_status==2);

    restore_email(my_list,"Anujna");
    assert(my_list->head->mail_data.mail_status==1);

    return 0;
}
