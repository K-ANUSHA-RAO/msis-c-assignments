#ifndef EMAILHEADER_H_INCLUDED
#define EMAILHEADER_H_INCLUDED

#define MAX_SIZE 20
#define MAX_SUBJECT_SIZE 30
#define MEM_ALLOC_FAILED NULL
#define INBOX 1
#define ARCHIVE 2
#define SUCCESS 1
#define EMPTY_LIST 0
#define SENDER_NOT_FOUND -1

struct _mail_data_
{
    char sender_name[MAX_SIZE];
    char receiver_name[MAX_SIZE];
    char subject[MAX_SUBJECT_SIZE];
    int mail_status; //Inbox or Archive
};
typedef struct _mail_data_ Mail_Data;

struct _email_
{
    Mail_Data mail_data;
    struct _email_ *ptr;
};
typedef struct _email_ Email;

struct _linked_list_
{
    Email *head, *tail;
    int count;
};
typedef struct _linked_list_ List;

//struct _archive_list_
//{
//    Email *head, *tail;
//    int count;
//};
//typedef struct _archive_list_ Archive_List;

List* initialize_list();
int insert_at_beg(List*, Mail_Data);
int archive_email(List*, char *sender_name);
int restore_email(List*, char *sender_name);

#endif // EMAILHEADER_H_INCLUDED
