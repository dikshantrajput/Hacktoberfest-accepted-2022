#include<stdio.h>
int main()
{
	int a[10],b[10],i,n,*p;
	printf("Enter Size of Array:");
	scanf("%d",&n);
	printf("Enter Elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{	
		b[i]=(a[i]*a[i]);
	}
	printf("Squares Of all Elements in an Array are:");
	for(i=0;i<n;i++)
	{
		printf("%d ",b[i]);
	}
}
