#include <stdio.h>
#include <stdlib.h>
#include "operations.c"


int main()
{
    char stringInput[10],intOrChar;
    int radius,checkEvenOrOdd,year;
    int randomNum1 = rand(),randomNum2 = rand();
    //Write a program that converts upper case to lower.
    printf("Enter uppercase Value\n");
    gets(stringInput);
    printf("\nValue in lower case: %s", convertToLower(stringInput));

    //Write a program to calculate the area of Circle.
    printf("\nEnter the radius of the circle\n");
    scanf("%d",&radius);
    printf("Area of the circle is : %f", areaOfCircle(radius));

    //Given two character inputs, find number of characters between them. For example, if
    //input is �A� and �E� the output is 3.
    char firstChar,secondChar;
    printf("\nEnter first character in uppercase: ")
    scanf("%c",&firstChar);
    printf("\nEnter second character in uppercase: ")
    scanf("%c",&secondChar);
    printf("\nNumber of characters between %c and %c :%d",firstChar,secondChar,numberOfCharBetween(firstChar,secondChar));


    //Write a program to convert temperature from Celsius to Fahrenheit
    float celsius;
    printf("\n Enter the Temparature in Celsius : ");
    scanf("%f",&celsius);
    printf("\n Temperature in Fahrenheit : %f ",convertTemp(celsius));

    //Check if entered number is even or odd.
    printf("\nEnter a number to check if it is even or odd\n");
    scanf("%d",&checkEvenOrOdd);
    if(isEven(checkEvenOrOdd))
        printf("\nYou have entered an even number");
    else
        printf("\nYou have entered a odd number");


    //Check if entered year is leap year or not.
    printf("\nEnter a year to check if it is a leap year or not\n");
    scanf("%d",&year);
    if(isLeapYear(year))
        printf("\nYou have entered a leap year");
    else
        printf("\nNot a leap year");

    //WAP to find power of 2^N using left shift operator.
    printf("\nEnter the value of  N to find 2^N\n");
    int power;
    scanf("%d",&power);
    printf("2^%d:%d",power,twoPowerN(power));

    //Check if given input is a character or integer. (Use integer input within the range 0-9)

    printf("\nEnter a integer or a character\n");
    scanf("%c",&intOrChar);
    if(ischaracter(intOrChar))
        printf("\n You have entered a character");
    else
        printf("\n You have entered a integer");

    //Generate two random numbers and find its sum (Hint: use rand() from stdlib.h)
    printf("\nGenerating 2 random numbers....\n 1st random number: %d \n 2nd random number: %d", randomNum1, randomNum2);
    printf("\nSum : %d",sumOfRandomNumbers(randomNum1,randomNum2));

    return 0;
}

