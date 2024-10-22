#ifndef BANK_HEADER_H_INCLUDED
#define BANK_HEADER_H_INCLUDED

#define NAME_SIZE 30
#define TYPE_SIZE 10
#define ACTIVE 1
#define INACTIVE 0

struct _transaction_
{
    int transaction_id;
    int sender_acc_no;
    char[] sender_bank_name;
    int receiver_acc_no;
    char[] receiver_bank_name;
    float amount;
};
typedef struct _transaction_ Transactions;

struct stack
{
    Transactions data[MAX_SIZE];
    int top;
    int size;
};
typedef struct stack *Stack;

struct _account_details_
{
    int acc_num;
    float balance;
    char[] acc_type[TYPE_SIZE];
    Stack transactions;
    int is_active;
};
typedef struct _account_details_ Accounts;

struct _acc_node_
{
    Accounts data;
    struct _acc_node_ *ptr;
};
typedef struct _acc_node_ Acc_Node;

struct _list_
{
    Acc_Node *head, *tail;
    int count;
};
typedef struct _list_ Account_List;

struct _bank_
{
    char[] bank_name[NAME_SIZE];
    Account_List accounts_data;
};
typedef struct _user_ Bank;

struct _bank_node_
{
    Bank data;
    struct _bank_node_ *ptr;
};
typedef struct _bank_node_ Bank_Node;



#endif // BANK_HEADER_H_INCLUDED
