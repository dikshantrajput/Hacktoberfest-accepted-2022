#include <stdio.h>

int main()
{
    int num;
    printf("Enter a Number: ");
    scanf("%d", &num);
    printf("%d \n", num % 2 == 0);

    /* other version to find Even and ODD */
  /* even --> 1
    odd -->0 */
    /*  int num;
     printf("Enter a Number: ");
     scanf("%d",&num);
      printf("%d \n", num % 2 == 0); */
  
    return 0;
}