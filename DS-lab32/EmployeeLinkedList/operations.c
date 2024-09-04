#include "commonHeader.h"

Firm* initialize_firm()
{
    Firm *my_firm;
    my_firm = (Firm *)malloc(sizeof(Firm));
    if(NULL == my_firm)return MEM_ALLOC_FAILED;

    my_firm->emp_head = NULL;
    my_firm->dept_head = NULL;
    my_firm->emp_count = 0;
    return my_firm;
}
EmployeeNode* get_new_employee_node(Employee emp_data)
{
    EmployeeNode *new_emp_node;
    new_emp_node = (EmployeeNode*)malloc(sizeof(EmployeeNode));
    if(NULL == new_emp_node)return MEM_ALLOC_FAILED;

    new_emp_node->emp_data = emp_data;
    new_emp_node->emp_ptr = NULL;

    return new_emp_node;
}
int insert_employee_beg(Firm my_firm, EmployeeNode my_emp, Employee emp_data)
{
    EmployeeNode *new_emp_node;
    new_emp_node = get_new_employee_node(emp_data);

    if(NULL == new_emp_node)return MEM_ALLOC_FAILED;

    if(my_firm->emp_count == 0){
        my_firm->emp_head->emp_data = new_emp_node;
    }
    else{

    }
}
int insert_department_beg(DeptNode my_dept, Department dept_data);
