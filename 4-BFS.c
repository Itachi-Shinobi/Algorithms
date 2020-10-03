//Program to print all nodes reachable from a given starting node in a digraph using BFS

#include<stdio.h> 

int a[20][20],q[20],visited[20],r=-1,f=0,i,j,n; 

void bfs(int v)
{ 
     visited[v]=1;  // vertex v is visited and marked 1
     for(i=1;i<=n;i++) 
                
          if(a[v][i] && !visited[i])  // if there is an edge from v to i and i is not visited
                q[++r]=i; 
                
          if(f<=r)    // if queue is empty   	
            	bfs(q[f++]); 
       
}
         
void main()
{ 
       int v; 
       printf("\nEnter no. of vertices:"); 
       scanf("%d",&n); 
       
       for(i=1;i<=n;i++) 
       { 
         	q[i]=0; 
         	visited[i]=0; 
       } 
        
       printf("\nEnter Adjacency Matrix of the graph:"); 
       
       for(i=1;i<=n;i++)
       { 
            for(j=1;j<=n;j++)
            { 
              	printf("nEnter a[%d][%d]:",i,j); 
              	scanf("%d",&a[i][j]); 
            } 
       } 
            
            
       printf("\nEnter the starting node:"); 
       scanf("%d",&v); 
                 
       bfs(v); //calling function
         
       printf("\nAll reachable nodes is/are \n"); 
         
       for(i=1;i<=n;i++)
       { 
             if(visited[i]) // if i is visited
                printf("%d \t",i); 
    
             else
               printf("\n%d is not reachable",i);
		
      	}
        
} 
    
    
