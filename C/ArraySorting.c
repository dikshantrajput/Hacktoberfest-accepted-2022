main()
{
	int a[100],rev[100],n,i,t,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	 	scanf("%d",&a[i]);
	printf("\nElements Are:");
	for(j=0;j<n;j++)
		printf("%d ",a[j]);
	printf("\nSorted Elements in Assending Order:");
	for(i=0;i<n;i++)
	{
		for(k=i;k<n;k++)
		{
			if(a[i]>=a[k])	
			{
				t=a[k];
				a[k]=a[i];
				a[i]=t;
			}
		}
	}
	for(i=0;i<n;i++)
			printf("%d ",a[i]);
	printf("\nSorted Elements in Descending Order:");
	for(k=n-1;k>=0;k--)
	{
		rev[k]=a[k];
		printf("%d ",rev[k]);
	}
	
}
