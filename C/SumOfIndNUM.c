main()
{
	int sum,a,rem;
	printf("Enter a:");
	scanf("%d",&a);
	while(a!=0)
	{
		rem=a%10;
		sum=sum+rem;
		a=a/10;
	}
	if(sum==a)
		printf("PERFECT NUMBER");
	else
		printf("NOT A PERFECT NUMBER");
}
