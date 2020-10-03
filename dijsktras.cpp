#include<iostream>
#include<stdlib>
#include<climits>
#define N 20

using namespace std;

int cost[N][N];

void parent(int vis,int p[N]){
//add the end condition of recursion
     if(vis==0)
        return;
     parent(p[vis],p);
     printf(" %d->",p[vis]);
     return;
}

void dijkstra(int n,int source){
	int dis[N],visited[N],count,min,nextnode,i,j,p[N];
	for(i=0;i<n;i++){
		dis[i]=cost[source][i]; //to initialize dis[] with the respective distances from the source
		visited[i]=0; //initially none of the nodes are visited
		p[i]=source;
	}

	dis[source]=0; //distance of source from itself is 0
	visited[source]=1; //mark source node as visited
	count=1; //1 node is visited(source)

	while(count<n) //loops until all the nodes are visited
	{
		min=INT_MAX;
		
		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
			if(dis[i]<min && !visited[i]){
				min=dis[i];
				nextnode=i;
			}
		
			visited[nextnode]=1;

			//to check if a better path exists through nextnode
			for(i=0;i<n;i++){
				if(!visited[i])
					if(min+cost[nextnode][i]<dis[i]){
						dis[i]=min+cost[nextnode][i];
						p[i]=nextnode;
					}
				count++;
			}
				
	}

	//to print distance of each node from the source node alongwith the path
	for(i=0;i<n;i++)
		if(i!=source){
			cout<<"\nDistance of node"<<i<<"to"<<source<<"with cost"<<dis[i]<<endl;
			parent(i,p);
            cout<<i;
		}
}

int main(){
	int i,j,n,source;
	cout<<"Enter no. of vertices:";
	cin>>n;
	printf("\nEnter the cost matrix:\n");

	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
		   cin>>cost[i][j];
		    if(cost[i][j]==0 && i!=j)
			cost[i][j]=INT_MAX;
		}

	printf("\nEnter the starting node:");
	cin>>source;
	printf("\n");
	dijkstra(n,source); 

	return 0;
}
