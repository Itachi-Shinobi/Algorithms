#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void Merge(int a[],int low,int high,int mid)
{
	int B[high-1],i=low,j=mid,k=low;
	
	while(i<mid && j<high)
	{
		if(a[i] < a[j])
			B[k++]=a[i++];
					
		else
			B[k++]=a[j++];

	}
	 
	for(i=low; i<high; i++) 
		a[i]=B[i];
}
			

void Sort(int a[],int low,int high)
{
	if(low <= high)
	{
		int mid=(low+high)/2;
		
		Sort(a,low,mid);
		Sort(a,mid+1,high-1);
		Merge(a,low,mid,high);
	}
}


void main()
{
	int i,j,n,min;
	clock_t start,end;
	
	printf("\nenter the size:");
	scanf("%d",&n);
	
	int a[n];
	
	printf("\n entering random elements into array");
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;
		printf("%d\t",a[i]);
	}
	
	start=clock();
	Sort(a,0,n-1);
	end=clock();
	
	printf("\nSorted array is:");
	
	for(i=1;i<=n;i++)
		printf("%d\t",a[i]);
		

	printf("\nStart time is %lf",(double)start/CLOCKS_PER_SEC);
	printf("\nEnd time is %lf",(double)end/CLOCKS_PER_SEC);
	printf("\nTotal time taken is %lf",(double)(end-start)/CLOCKS_PER_SEC);
}
	
	
	
