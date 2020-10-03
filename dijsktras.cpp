#include<iostream>

using namespace std;

void parent(int vis,int p[]){
     printf(" %d->",p[vis]);
     parent(p[vis],p);
     return;
}

int cost[20][20];
void dijkstra(int n,int source){
	int dis[20],visited[20],count,min,nextnode,i,j,p[20];
	for(i=0;i<n;i++){
		dis[i]=cost[source][i]; //to initialize dis[] with the respective distances from the source
		visited[i]=0; //initially none of the nodes are visited
		p[i]=source;
	}

	visited[source]=1; //mark source node as visited
	count=1; //1 node is visited(source)

	while(count<n) //loops until all the nodes are visited
	{
		min=999;
		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
			if(dis[i]<min && !visited[i]){
				min=dis[i];
				nextnode=i;
			}

			//to check if a better path exists through nextnode
			for(i=1;i<n;i++){
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
		    if(cost[i][j]==0)
			cost[i][j]=-1;
		}

	printf("\nEnter the starting node:");
	cin>>source;
	printf("\n");
	dijkstra(n,source); 

	return 0;
}
