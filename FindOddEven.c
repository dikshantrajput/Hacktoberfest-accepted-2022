#include<stdio.h>
#include<conio.h>
main()
{
   int n;
   clrscr();

   printf("Enter the value :");
   scanf("%d",&n);

   if(n%2==0)
   {
       printf("Your value (%d) is even",n);
   }
   else
   {
       printf("Your value (%d) is Odd",n);
   }
   getch();

}
