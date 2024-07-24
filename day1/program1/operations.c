#include <ctype.h>
#include <stdbool.h>
#include "headerFiles.h"

char * convertToLower( char inputString[10] ){
    for(int i=0; i < strlen(inputString); i++){
       inputString[i] = tolower(inputString[i]);
    }
    return inputString;
}

float areaOfCircle( int radius ){
    return PI*radius*radius;
}

bool isEven( int value ){
    if(value%2==0)
        return true;
    else
        return false;
}

bool isLeapYear( int year ){
    if(year%400 == 0)
        return true;
    else if(year%100 == 0)
        return false;
    else if(year%4 ==0)
        return true;
    else return false;
}

int sumOfRandomNumbers(int num1, int num2){
    return num1+num2;
}

bool ischaracter(char intOrChar){
    return isalpha(intOrChar);
}
