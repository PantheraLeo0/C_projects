#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    float valueOne, valueTwo;
    char operator;
    float result;

    system("cls");

    printf("\n\tSIMPLE CALCULATOR\n\n");
    printf("---------------------------------------\n");
    printf("Enter calculation : ");
    scanf("%f %c %f",&valueOne,&operator,&valueTwo);

    system("cls");

    switch(operator){
        case '+' : printf("%.0f + %.0f = %.0f\n",valueOne,valueTwo,valueOne + valueTwo);
        break;
        case '-' : printf("%.0f - %.0f = %.0f\n",valueOne,valueTwo,valueOne - valueTwo);
        break;
        case '*' : printf("%.0f * %.0f = %.0f\n",valueOne,valueTwo,valueOne * valueTwo);
        break;
        case '/' : printf("%.0f / %.0f = %.2f\n",valueOne,valueTwo,valueOne / valueTwo);
        break;
    }
    return 0;
}