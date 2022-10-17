#include<stdio.h>
int FindNumber(int *a,int n)
{
	int sum=0,i,j,totalsum;
	//1
	for(i=0;i<n;i++) 
		sum+=a[i];	
	totalsum=((n+1)*(n+2))/2; 
	//2
	//totalsum=((n+1)*(n+2))/2; for(i=0;i<n;i++) totalsum=totalsum-a[i];
	printf("Missing Element is: %d",totalsum-sum);
	//3
	// for(i=0;i<n;i++) if(a[i]!=i+1) print("%d",i+1);
}
int main()
{
	int a[100],i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	FindNumber(a,n);
	return 0;
}
