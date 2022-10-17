#include<stdio.h>
#include<ctype.h>
int main()
{
	int i,j=0;
	char a[10],b[10];
	printf("Enter the String: ");
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		if(isalpha(a[i]))
		{
			b[j++]=a[i];
		}
	}
	puts(b);
	
	return 0;
}

	
