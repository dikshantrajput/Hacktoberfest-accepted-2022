#include<stdio.h>
int max(int *a,int n)
{
	int i,j=1,t,max;
	for(i=0;i<n;i++,j++)
	{
		if(a[i]>a[j])
			max=a[i];
	}
	return max;
}
int min(int *a,int n)
{
	int i,j=1,t,min;
	for(i=0;i<n;i++,j++)
	{
		if(a[i]<a[j])
			min=a[i];
	}
	return min;
}
int main()
{
	int a[10],i,n,q,p;
	printf("Enter Size of Array:");
	scanf("%d",&n);
	printf("Enter Elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	p=min(a,n);
	q=max(a,n);
	printf("Largest Element is: %d",q);
	printf("\nSmallest Element is: %d",p);
	return 0;
}
