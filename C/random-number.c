#include <stdio.h>

#include <stdlib.h>

int main() {
    int c, n, x;
    char a[30];
    printf("If u need any prefix write it else press enter ");
    scanf("%c", & a);
    printf("How many random numbers you need");
    scanf("%d", & x);
    printf("%d random numbers are :-\n", x);
    for (c = 1; c <= x; c++) {
        n = rand() % 1000000 + 1;
        if (a == NULL) {
            printf("%d\n", n);
        } else {
            printf("%c%d\n", a, n);
        }
    }
    return 0;
}

/* This Code is Contributed By Akshat Jain (@akshat-jjain) */
