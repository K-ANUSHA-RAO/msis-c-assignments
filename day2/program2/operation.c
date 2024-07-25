#include "headerFile.h"
#include <stdbool.h>

void findSumOfDigits(){
    int number;
    printf("\nEnter a 5 digit number: ");
    scanf("%d",&number);
    printf("\nSum of the digits is: %d ",returnSumOfDigits(number));
}
int returnSumOfDigits(int number){
    int sum=0,remainder;
    for(int i=0;i<5;i++){
        remainder = number%10;
        sum+=remainder;
        number=number/10;
    }
    return sum;
}

void reverseNumber(){
    int number;
    printf("\nEnter a number: ");
    scanf("%d",&number);
    printf("\nReverse of number %d is : %d ",number,returnReverseNum(number));
}
int returnReverseNum(int number){
    int newNumber=0;
    while (number>0){
        newNumber = newNumber*10+number%10;
        number=number/10;
    }
    return newNumber;
}

void occuranceOfDigit(){
    int number,digit;
    printf("\nEnter a number with repeated digits: ");
    scanf("%d",&number);
    printf("\nEnter the digit to find its occurrence: ");
    scanf("%d",&digit);
    printf("\nOccurrence of digit %d in number %d is : %d ",digit,number,returnOccuranceOfDigit(number,digit));
}
int returnOccuranceOfDigit(int number,int digit){
    int count=0;
    while(number>0){
        if(number%10==digit)
            count++;
        number/=10;
    }
    return count;
}

void checkPalindrome(){
    int number;
    printf("\nEnter a number to check if its a palindrome: ");
    scanf("%d",&number);
    if(returnPalindrome(number))
        printf("\nThe number %d is palindrome.",number);
    else
        printf("\nThe number %d is not a palindrome.",number);
}
bool returnPalindrome(int number){
    int newNumber=0;
    int initialInputNum=number;
    while (number>0){
        newNumber = newNumber*10+number%10;
        number=number/10;
    }
    if(newNumber==initialInputNum)
        return true;
    else
        return false;
}

void generatePrimeNumbers(){
    int number,count=0;
    printf("\nEnter a number N to generate prime numbers: ");
    scanf("%d",&number);
    firstNPrimeNumbers(number);
}

int isPrime(int num){
   /* To check given number is prime */
    int i;
    for(i = 2; i <= num/2; i++)
        if(num % i == 0) return 0;
    return 1;

}
int firstNPrimeNumbers(int num){
    int count = 0, i;
    for(i = 2; count < num; i++)
    {
        if(isPrime(i))
        {
            printf("%d ,",i);
            count++;
        }
    }
    printf("\n");
    if(count == num ) return 1;
    else return 0;
}
void menuCode(){
    bool exitCheck=true;
    while(exitCheck){
        int firstNum,secondNum,operation;
        printf("\nEnter 2 numbers:");
        printf("\nFirst number:");
        scanf("%d",&firstNum);
        printf("\nSecond number:");
        scanf("%d",&secondNum);
        printf("\n----Menu----\n");
        printf("\n 0. Exit from menu");
        printf("\n 1. Sum");
        printf("\n 2. Diffrence");
        printf("\n 3. Product");
        printf("\n Enter the operation number: ");
        scanf("%d",&operation);
        switch(operation){
            case 1:
                printf("\nSUM: %d ", sum(firstNum,secondNum));
                break;
            case 2:
                printf("\nDIFFRENCE:%d ", diffrence(firstNum,secondNum));
                break;
            case 3:
                printf("\nPRODUCT:%d ",product(firstNum,secondNum));
                break;
            case 0:
                exitCheck=false;
                break;
            }
    }
}
int sum(int firstNum,int secondNum){
    return firstNum+secondNum;
}
int product(int firstNum,int secondNum){
    return firstNum*secondNum;
}
int diffrence(int firstNum,int secondNum){
    return firstNum-secondNum;
}
