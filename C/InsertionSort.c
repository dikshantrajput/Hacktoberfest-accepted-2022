main()
{
	int n,i,j,a[100],temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
			while(temp<a[j] && j>=0)
			{
				
				a[j+1]=a[j];
				j=j-1;
			}
		a[j+1]=temp;
	}
	printf("Sorted Array:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	
}
