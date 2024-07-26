#include "headerFile.h"

void binaryToDecimal(){
    int binaryInput;
    printf("\nEnter binary number:");
    scanf("%d",&binaryInput);
    printf("Decimal number for the entered binary number: %d",returnDecimalNumber(binaryInput));
}
int returnDecimalNumber(int binaryInput){
    int num = binaryInput;
    int decimalNumber = 0;
    int base = 1;
    int temp = num;
    while(temp){
        //Get the last digit
        int lastDigit = temp%10;

        //update temp val with remaining digits in number
        temp = temp/10;
        decimalNumber+=lastDigit*base;
        base = base*2;
    }
    return decimalNumber;
}

void decimalToBinary(){
    int decimalInput;
    printf("\nEnter a decimal number");
    scanf("%d",&decimalInput);
    printf("\nBinary number for the given decimal number:");
    returnBinaryNumber(decimalInput);
}

void returnBinaryNumber(int decimalInput){
    int binaryNumber[ARRAY_SIZE];
    int i=0;
    while(decimalInput>0){
        //store the remainder
        binaryNumber[i] = decimalInput%2;
        decimalInput = decimalInput/2;
        i++;
    }
    for (int j=i-1;j>=0;j--){
            printf("%d",binaryNumber[j]);
    }
}
void sumOfPrevThree(){
    int limit;
    printf("\n Enter the limit for the sequence:");
    scanf("%d",&limit);
    printSeries(limit);

}

void printSeries(int limit){
    for(int i=1;i<=limit;i++){
        printf("%d ",returnSequence(i));
    }
}

int returnSequence(int limit){
    if(limit==0||limit==1||limit==2)
        return 0;
    if(limit==3)
        return 1;
    else
        return returnSequence(limit-1)+
            returnSequence(limit-2)+
            returnSequence(limit-3);
}

void returnTriangle(){
    int rows,i,j;
    printf("\nEnter the number of rows in the triangle pattern: ");
    scanf("%d",&rows);
    for(i=0;i<=rows;i++){
        for(j=0; j<=(i-1);j++){

            printf("*");
        }
        for(j=0;j<i;j++){

            printf(" ");
        }

        printf("\n");
    }
}

void returnInvertedTriangle(){
    int rows,i,j;
    printf("\nEnter the number of rows in the triangle pattern: ");
    scanf("%d",&rows);
    for(i=0;i<rows;i++){
        for(j=0;j<i;j++){

            printf(" ");
        }
        for(j=0; j<rows-i;j++){

            printf("*");
        }
        printf("\n");
    }
}

void sumOfTwoDigitAsNine(){
    int limit;
    printf("\n Enter the limit for the sequence: ");
    scanf("%d",&limit);
    returnSequenceNine(limit);
}
void returnSequenceNine(int limit){
    //int firstNum=18;
    for(int i=2;i<limit+2;i++){
        if((9*i)<=90)
            printf("%d\n ",9*i);
    }
}
