#include<stdio.h>
int main(){
     char a;
     printf("Enter a your value : ");
     scanf("%c",a);
     printf("%c", (a<='1' && a<='9'));
    return 0;
}