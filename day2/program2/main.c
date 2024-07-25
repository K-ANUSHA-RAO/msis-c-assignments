#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "operation.c"

int main()
{
    bool check=true;
    int programNumber;
    while(check){
        printf("\n ----Enter the program to run----- ");
        printf("\n 0. Exit from menu");
        printf("\n 1. Enter a 5 digit number and find the sum of its digits.");
        printf("\n 2. Write a program to reverse the number.");
        printf("\n 3. Write a program to count the occurrences of a digit in a number.");
        printf("\n 4. WAP to check if a given number is a palindrome.");
        printf("\n 5. Generate the first 'N' prime numbers.");
        printf("\n 6. Write a C program to display and find the sum of the series 1+11+111+....111 up to n..");//pending
        printf("\n 7. Write a menu driven program to read two integers & find their sum, difference & product.");
        printf("\n");
        scanf("%d",&programNumber);
        switch(programNumber){
            case 7:
                menuCode();
                break;
            case 5:
                generatePrimeNumbers();
                break;
            case 4:
                checkPalindrome();
                break;
            case 3:
                occuranceOfDigit();
                break;
            case 2:
                reverseNumber();
                break;
            case 1:
                findSumOfDigits();
                break;
            case 0:
                check = false;
                break;
        }
    }
    return 0;
}
