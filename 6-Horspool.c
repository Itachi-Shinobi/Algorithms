// Program to Implement Horspool algorithm for String matching.

#include<stdio.h>
#include<string.h>
#define MAX 250

int table[MAX];

// creating shift table
void shiftTable(char p[])
{
	int i,j,m;
	m=strlen(p);
	
	for(i=0;i<MAX;i++)
		table[i]=m;  // initialising with length of pattern
		
	for(j=0;j<m-1;j++)
		table[p[j]]=m-1-j;
}

int Horspool(char src[],char p[])
{
	shiftTable(p);
	
	int i,j,k,m,n;
	n=strlen(src);
	m=strlen(p);
	i=m-1;
	
	while(i<n)
	{
		k=0;
		
		while((k<m) && (p[m-1-k] == src[i-k]))
		 k++;
		 
		 if(k==m)
		 	return(i+1-m);  //return the index where string is found

		 else i=i+table[src[i]];   //shifting i by shift value of character calculated in shift table
	}
	
	return -1;   // if not found return -1
}

void main()
{
	char src[100],p[100];
	int pos;
	
	printf("Enter String\n:");
	gets(src);
	
	printf("\nEnter pattern to be matched:\n");
	gets(p);
	
	pos=Horspool(src,p);  //calling function and assigning the return value to pos
	
	
	if(pos>=0) //if string is present
		printf("\n Pattern found at position:  %d\n",pos+1);
	else   
		printf("\nPattern not found \n");
}
