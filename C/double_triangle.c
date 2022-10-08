#include<stdio.h>
void main()
{
    int i,j,n,s,a,b,l,p,t,num=0;
    printf("enter the odd number of rows:");
    scanf("%d",&n);                  
    if(n%2==0)
    {
     printf("invalid input");
    } 
    else
    {
      a=(n+1)/2;           
      b=a+1;             
      for(i=a;i>=1;i--)
      {
        for(s=(a-i);s>=1;s--)
        {
          printf(" ");
        }
        for(j=(2*i-1);j>=1;j--)
        {
            printf("*");
        }
        printf("\n");
      }  
      for(l=b;l<=n;l++)   
      {
        for(p=(n-l);p>=1;p--)   
        {
            printf(" ");
        }      
        for(t=l;t>=(l-2*num-2);t--)
        {
            printf("*");

        }
        num++;
        printf("\n");
      }    

    }        

}
