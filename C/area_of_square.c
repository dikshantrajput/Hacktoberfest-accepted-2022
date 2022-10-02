#include <stdio.h>

int main()
{
    float side, area;
    printf("Enter the Side of Square (in cm) \n");
    scanf("%f", &side);
    area = (side * side);
    printf("Area of Square is : %f cm.sq", area);
    return 0;
}