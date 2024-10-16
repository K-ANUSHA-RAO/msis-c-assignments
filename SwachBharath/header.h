#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define MAX_SIZE 50
#define MEM_ALLOC_FAILED NULL
#define FAILED 0
#define SUCCESS 1
#define LIST_EMPTY 0
#define REGISTERED 1
#define NOT_REGISTERED 0
#define ALLOWED 1
#define NOT_ALLOWED 0
#define DATE_SIZE 11 // To store DD-MM-YYYY format

struct _student_
{
    int id;
    char name[MAX_SIZE];
    char gender; // 'M' for Male, 'F' for Female
    int otp;
    char registration_date[DATE_SIZE]; // String to store date in DD-MM-YYYY format
};
typedef struct _student_ Student;

struct _node_
{
    Student data;
    struct _node_ *ptr;
};
typedef struct _node_ Node;

struct _linked_list_
{
    Node *head, *tail;
    int count;
    int male_count;
    int female_count;

};
typedef struct _linked_list_ List;


List * initialize();
int insert_at_end(List*, Student);
int delete_student(List*, Student);
void display_list(List*);
#endif // HEADER_H_INCLUDED
