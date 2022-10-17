#include<stdio.h>
int main()
{
	int a[10],i,n,*p,sum=0;
	printf("Enter Size of Array:");
	scanf("%d",&n);
	printf("Enter Elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		sum+=a[i];
	}
	printf("Array Sum:%d",sum);
	return 0;
}
	
