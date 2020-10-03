#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int Partition(int a[],int low,int high)
{
	int pivot=a[low],i=low+1,j=high;
	
	while(i <=j)
	{
		while(a[i] <= pivot)
			i++;
		
		while(a[j]>pivot)
			j--;
		
		if( i < j)
		{
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	
	int t=a[low];
	a[low]=a[j];
	a[j]=pivot;
	
	return j;
	
}

void Quick(int a[],int low,int high)
{
	if(low<=high)
	{
	 int pos=Partition(a,low,high);
	 Quick(a,low,pos-1);
	 Quick(a,pos+1,high);
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
		//scanf("%d",&a[i]);
		a[i]=rand()%100;
		printf("%d\t",a[i]);
	}
	
	start=clock();
	Quick(a,0,n-1);
	end=clock();
	
	printf("\nSorted array is:");
	
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
		

	printf("\nStart time is %lf",(double)start/CLOCKS_PER_SEC);
	printf("\nEnd time is %lf",(double)end/CLOCKS_PER_SEC);
	printf("\nTotal time taken is %lf",(double)(end-start)/CLOCKS_PER_SEC);
}
