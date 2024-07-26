#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "operations.c"

int main()
{
    bool check=true;
    int programNumber;
    while(check){
        printf("\n ----Enter the program to run----- ");
        printf("\n 0. Exit from menu");
        printf("\n 1. WAP to convert a binary number to decimal");
        printf("\n 2. WAP to convert a decimal to binary number");
        printf("\n 3. Generate a sequence of numbers such that every number in the sequence is the sum of the previous three numbers. The first three numbers are 0,0,1.");
        printf("\n 4. WAP to print the right angle triangle with input N as number of rows");
        printf("\n 5. WAP to print the inverted right angle triangle with input N as number of rows");
        printf("\n 6. Write a C program, which will print two digit numbers whose sum of both digit is nine.");
        printf("\n");
        scanf("%d",&programNumber);
        switch(programNumber){
            case 6:
                sumOfTwoDigitAsNine();
                break;
            case 5:
                returnInvertedTriangle();
                break;
            case 4:
                returnTriangle();
                break;
            case 3:
                sumOfPrevThree();
                break;
            case 2:
                decimalToBinary();
                break;
            case 1:
                binaryToDecimal();
                break;
            case 0:
                check = false;
                break;
        }
    }

    return 0;
}
