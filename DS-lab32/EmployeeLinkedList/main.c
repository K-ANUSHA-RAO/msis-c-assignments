#include <stdio.h>
#include <stdlib.h>
#include "operations.c"
#include <assert.h>

int main()
{
    Firm *test_firm;
    test_firm = initialize_firm();
    assert(test_firm->emp_head == NULL);
    assert(test_firm->dept_head == NULL);
    assert(test_firm->emp_count == 0);



    return 0;
}
