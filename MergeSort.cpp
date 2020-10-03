#include<stdlib.h>
#include<stdio.h>
// #include<time.h>
//don't use time it's not required that's just for knowledge

void Merge(int a[],int low,int high,int mid)
{
	//check the size of B array and value of j
	int B[high],i=low,j=mid+1,k=low;
	
	//notice the equal to sign
	while(i<=mid && j<=high)
	{
		if(a[i] < a[j])
			B[k++]=a[i++];
					
		else
			B[k++]=a[j++];

	}
	 
	//you forgot to copy the remaining elements to B array if there are any
	
	while (i <= mid)
		B[k++] = a[i++];

	while (j <= high)
		B[k++] = a[j++];

	//notice the equal to sign
	for(i=low; i<=high; i++) 
		a[i]=B[i];
}
			

void Sort(int a[],int low,int high)
{
	if(low < high)
	{
		int mid=(low+high)/2;
		
		Sort(a,low,mid);
		Sort(a,mid+1,high);
		Merge(a,low,mid,high);
	}
}


void main()
{
	int i,j,n,min;
// 	clock_t start,end;
	
	printf("\nenter the size:");
	scanf("%d",&n);
	
	int a[n];
	
	printf("\n entering random elements into array");
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;
		printf("%d\t",a[i]);
	}
	
// 	start=clock();
	Sort(a,0,n-1);
// 	end=clock();
	
	printf("\nSorted array is:");
	
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
		

// 	printf("\nStart time is %lf",(double)start/CLOCKS_PER_SEC);
// 	printf("\nEnd time is %lf",(double)end/CLOCKS_PER_SEC);
// 	printf("\nTotal time taken is %lf",(double)(end-start)/CLOCKS_PER_SEC);
}
	
	
	
