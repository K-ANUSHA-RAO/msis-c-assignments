#include <stdio.h>
#include <stdlib.h>
#include "arrayOperations.c"
#include <assert.h>
int main()
{
    Array testArray1, testArray2;
    int result;
    testArray1 = intializeArray(5);
    testArray2 = intializeArray(6);
    assert(testArray1.c_size == 0 && testArray1.t_size == 5);

    testArray1 = insertArrayElements(testArray1,10,&result);
    assert(result == SUCCESS);
    testArray1 = insertArrayElements(testArray1,2,&result);
    assert(result == SUCCESS);
    testArray1 = insertArrayElements(testArray1,11,&result);
    assert(result == SUCCESS);
    testArray1 = insertArrayElements(testArray1,5,&result);
    assert(result == SUCCESS);
    testArray1 = insertArrayElements(testArray1,3,&result);
    assert(result == SUCCESS);

    testArray2 = insertArrayElements(testArray2,10,&result);
    assert(result == SUCCESS);
    testArray2 = insertArrayElements(testArray2,22,&result);
    assert(result == SUCCESS);
    testArray2 = insertArrayElements(testArray2,11,&result);
    assert(result == SUCCESS);
    testArray2 = insertArrayElements(testArray2,15,&result);
    assert(result == SUCCESS);
    testArray2 = insertArrayElements(testArray2,13,&result);
    assert(result == SUCCESS);
    testArray2 = insertArrayElements(testArray2,93,&result);
    assert(result == SUCCESS);

    assert(countPrimeNumbers(testArray1)==4);
    assert(countSubsetOfArrayBeingPrime(testArray1)==3);

    return 0;
}
