main()
{
	int a[100],rev[100],prod=1,n,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	 	scanf("%d",&a[i]);
	printf("\nElements Are:");
	for(j=0;j<n;j++)
		printf("%d ",a[j]);
	printf("\nReversed Elements Are:");
	for(k=n-1;k>=0;k--)
	{
		rev[k]=a[k];
		printf("%d ",rev[k]);
	}
	/*for(j=0;j<n;j++)
		printf("%d ",rev[j]);*/
}
	
		

