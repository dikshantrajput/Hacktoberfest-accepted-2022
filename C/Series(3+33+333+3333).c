#include<stdio.h>
void main()
{
	int n,i,s=0,res=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		s=(s*10)+3;
		res=res+s;
		printf("%d",s);
		if(i<n)
			printf("+");
	}
	printf("\n%d",res);	
}
