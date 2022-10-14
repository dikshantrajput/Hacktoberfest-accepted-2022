#include <stdio.h>
#define MAX 20
int main()
{
    int a[MAX],n,i,j,c;
    printf("Enter the number of elements you want: ");
    scanf("%d",&n);
    printf("The entered elements are: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int isSorted=0;
    for(i=0;i<n-1;i++)    // for number of pass
    {
        printf("Working on pass number %d\n",i+1);
        isSorted=1;
        for(j=0;j<n-i-1;j++)    // for comparison in each pass
        {
            if(a[j]>a[j+1])
            {
               c=a[j];
               a[j]=a[j+1];
               a[j+1]=c;
               isSorted=0;
            }
        }
        if(isSorted)
        break;
    }
        printf("The sorted elements are: ");
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        return 0;
    }
