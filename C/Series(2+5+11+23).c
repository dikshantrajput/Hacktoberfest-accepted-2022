#include<stdio.h>
void main()
{
	int n,i,s=2,res=0;
	scanf("%d",&n);
	printf("2+");
	for(i=1;i<n;i++)
	{
		s=(s*2)+1;
		res=res+s;
		printf("%d",s);
		if(i<n-1)
			printf("+");
	}
	printf("\n%d",res);	
}
