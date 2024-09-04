#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED
#define MAX_SIZE 30
#define FULL -1
#define SUCCESS 1
#define FAIL 0
#define NOT_PRIME 0
struct _array_ {
    int array[MAX_SIZE];
    int c_size,t_size;
};
typedef struct _array_ Array;

Array intializeArray(int size);

Array insertArrayElements(Array,int data,int *result);

int countPrimeNumbers(Array);
int isPrime(int);
int mergeArray(Array array1,Array array2);



#endif // HEADERS_H_INCLUDED
