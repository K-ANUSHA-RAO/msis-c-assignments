#ifndef USER_HEADER_H_INCLUDED
#define USER_HEADER_H_INCLUDED

#define NAME_SIZE 30
struct _user_
{
    char[] user_name[NAME_SIZE];
    int mob_num;
    int account_number;
    char[] bank_name[NAME_SIZE];
};
typedef struct _user_ User;

struct _node_
{
    User data;
    struct _node_ *ptr;
};
typedef struct _node_ Node;

struct _list_
{
    Node *head, *tail;
    int count;
};
typedef struct _list_ User_List;

User_List* initialize_user_list();
User_List* add_user_at_beg(User_List*, User data);
int search_user(User_List*, char[] user_name, int mob_num);

#endif // USER_HEADER_H_INCLUDED
