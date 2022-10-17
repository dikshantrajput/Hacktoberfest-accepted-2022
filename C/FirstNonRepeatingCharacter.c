#include<stdio.h>
int main()
{
	char a[100],s[100];
	int i,j,k,c=0,flag=0;
	gets(a);	
	for(i=0,k=0;a[i]!='\0';i++)
	{
		for(j=i+1;a[j]!='\0';j++)
		{
			if(a[i]==a[j])
			{
				flag=0;
				break;
			}
			else
				flag=1;
		}
		if(flag==1)
		{
			s[k]=a[i];
			k++;
		}
	}
	printf("First Non-Repeating Character: ",s[0]);
}
