#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
int a,b;
float c;
for (a=1;a<=100;a++)
{
for (b=1;b<=100;b++)
{
c=sqrt(a*a + b*b);
if (c == (int)c){

printf("( %d , %d , %d )\n",a,b,(int)c);
}
}

}return 0;
}
