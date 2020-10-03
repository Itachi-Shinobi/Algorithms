#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int H[100];


void display(int n)
{
	int i;
	
	for(i=1 ;i<=n;i++)
		printf("%d\t",H[i]);
}

void Heapify(int n)
{
	int i,k,v,j,heap=1;
	
	//starting to heapify from the last parent node
	for(i=n/2 ;i>=1 ; i--)
	{
		k=i;
		v=H[k];
		heap=0;
		
		while(!heap && (2*k <=n))
		{
			j=2*k;
			
			//if there are 2 children
			if(j<n)
			{
				if(H[j] < H[j+1])
					j++;
			}		
			
			//if parent node's value is greater than child node then make heap 1
			if(v>=H[j])
				heap=1;
			
			//else swap with the child node which has greatest value
			else
			{
				H[k]=H[j];
				k=j;
				
			}
			H[k]=v;
		}
	}
	
	
}

void HeapSort(int n)
{
	int i=1,j,k;
	
	for(j=n ;j>=1; j--)
	{
		Heapify(j);
		//swapping first and last node's values
		k=H[1];
		H[1]=H[j];
		H[j]=k;
		
	}
}

void main()
{
	int n,i;
	clock_t start,end;
	
	printf("enter how many nodes\n");
	scanf("%d",&n);
	
	printf("\nentering random values");
	
	for(i=1;i<=n;i++)
	{
		int e;
		scanf("%d",&e);
		H[i]=e;
	}
		

	start=clock();	
	HeapSort(n); 
	end=clock();

	//displaying Sorted Elements
	printf("\nSorted array is\n:");	
	display(n);

	printf("\nStart time is : %lf",(double)(start)/CLOCKS_PER_SEC);
	printf("\nEnd time is : %lf",(double)(end)/CLOCKS_PER_SEC);
	printf("\nTotal time taken is : %lf",(double)(end-start)/CLOCKS_PER_SEC);

}
	
	
		
	
	
	
	
	
