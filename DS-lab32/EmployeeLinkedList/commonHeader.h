#ifndef COMMONHEADER_H_INCLUDED
#define COMMONHEADER_H_INCLUDED

#define NAME_SIZE 20
#define MEM_ALLOC_FAILED NULL

struct _department_
{
    int dept_id;
    char dept_name[NAME_SIZE];
};
typedef struct _department_ Department;

struct _employee_
{
    int emp_id;
    char emp_name[NAME_SIZE];
    int age;
    float salary;
};
typedef struct _employee_ Employee;

struct _employee_node_
{
    Employee emp_data;
    struct _employee_node_ *emp_ptr;
};
typedef struct _employee_node_ EmployeeNode;

struct _department_node_
{
    Department dept_data;
    struct _department_node_ *dept_ptr;
};
typedef struct _department_node_ DeptNode;

struct _firm_
{
    EmployeeNode *emp_head;
    DeptNode *dept_head;
    int emp_count;
};
typedef struct _firm_ Firm;

Firm* initialize_firm();
int insert_employee_beg(Firm my_firm, EmployeeNode my_emp, Employee emp_data);
int insert_department_beg(DeptNode my_dept, Department dept_data);


#endif // COMMONHEADER_H_INCLUDED
