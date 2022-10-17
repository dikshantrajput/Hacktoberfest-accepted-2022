#include<stdio.h>
int main()
{
	int a[100],b[100],c[100],d[100],i,n,j,k=0,temp,s=0;
	printf("Enter Size=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(i=0,j=n;i<n;i++,j++)
	{
		c[i]=a[i];	
		c[j]=b[i];
	}
	for(i=0;i<2*n;i++)
	{
		for(j=i;j<2*n;j++)
		{
			if(c[i]>c[j])
			{
				temp=c[i];
				c[i]=c[j];
				c[j]=temp;
			}	
		}
	}
	for(i=0;i<2*n;i++)
	{
		s=0;
		for(j=i;j<2*n;j++)
		{
			if(c[i]==c[j])
			{
				s=s+1;
			}
		}
		if(s==1)
		{
			d[k]=c[i];
			k++;
		}
	}
	printf("%d\n",k);
	for (i=0;i<k;i++)
		printf("%d ",d[i]);
	return 0;
}
