#include "headers.h"

Array intializeArray(int size){
 Array myArray;

 myArray.c_size = 0;
 myArray.t_size = size>0 && size<MAX_SIZE ? size:MAX_SIZE;

 return myArray;
}

Array insertArrayElements(Array myArray,int data,int *result){

    if(myArray.c_size == myArray.t_size){
        *result = FULL;
    }
    else{
        myArray.array[myArray.c_size++] = data;
        *result = SUCCESS;
    }

    return myArray;
}

int countPrimeNumbers(Array myArray){
    int count=0;
    for(int i=0;i<myArray.c_size;i++){
    if(isPrime(myArray.array[i]))count++;
    }
    return count;
};

int isPrime(int number){
    if(number==0||number==1)return 0;
    for(int j =2; j<number/2; j++){
            if(number%j==0) return 1;
            else return 0;
        }
}

int countSubsetOfArrayBeingPrime(Array myArray){
     int count = 0;
     for(int i=0 ; i<myArray.c_size;i++){
        for(int j=i+1; j<myArray.c_size;j++){
            if(isPrime(myArray.array[i] + myArray.array[j])) count++;
        }
     }
     return count;
}

/*int mergeArray(Array array1,Array array2){
int updateSize = array1.c_size + array2.c_size;
array1.t_size = updateSize;
array1.array = realloc(array1.array, sizeof(int)*updateSize);

for(int i =0;i<array2.c_size;i++){
    array1.array = insertArrayElements(array1.array,*(array2.array+i));
}
}*/
