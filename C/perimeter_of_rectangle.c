#include <stdio.h>

int main()
{
    float length,breath ,perimeter;
    printf("Enter the Length  of Rectangle \n");
    scanf("%f", &length);
     printf("Enter the Breath of Rectangle \n");
     scanf("%f",&breath);
    perimeter = (2*(length+breath));
    printf("Perimeter of Rectangle : %f ", perimeter);
    return 0;
}