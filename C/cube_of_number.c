#include <stdio.h>

int main()
{
    float num,cube;
    printf("Enter a number \n");
    scanf("%f", &num);
    
    cube = (num*num*num);
    printf("Cube of your number is  : %f ",cube);
    return 0;
}