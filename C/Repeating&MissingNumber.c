#include <stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter the no. of elements in array: ");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter the array elements(using numbers 1 to %d): ", n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for(int i=0; i<n; i++)
    {
        if(a[abs(a[i])-1] >= 0)
        {
            a[abs(a[i])-1] = -a[abs(a[i])-1];
        }
        else printf("\nRepeating number is : %d", abs(a[abs(a[i])-1]));
    }
    for(int i=0; i<n; i++)
    {
        if(a[i] > 0){
            printf("\nMissing number is  : %d", i+1);
            break;
        }
    }
    return 0;
}
