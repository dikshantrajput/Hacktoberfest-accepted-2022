#include <stdio.h>

int main(void)
{
    int yr;
    printf("Enter the year to check \n");
    scanf("%d", &yr);

    if (yr % 4 == 0 && yr % 100 == 0 && yr % 400 == 0)
        printf("It is a leap year");

    else if (yr % 4 == 0 && yr % 100 != 0)
        printf("It is a leap year");

    else
        printf("It is not a leap year");

    return 0;
}