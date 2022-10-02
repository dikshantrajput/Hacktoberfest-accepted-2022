#include <stdio.h>

int main()
{
    float radius, area;
    printf("Enter the radius of Circle(in cm) \n");
    scanf("%f", &radius);
    area = (3.14 *radius * radius);
    printf("Area of Circle is : %f cm.sq", area);
    return 0;
}