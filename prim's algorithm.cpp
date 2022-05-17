#include<bits/stdc++.h>
using namespace std;
int vertex_with_min_edge_weight(int key[],int V,bool mst[])
{
	int min=INT_MAX,min_index;
	for(int i=0;i<V;i++)
	{
		if(mst[i]==false && key[i]<min)
		{
			min=key[i];
			min_index=i;
		}
	}
	return min_index;
}
int main()
{
	int V,E;
	int source,destination,weight;
	cout<<"Enter the number of vertices : ";
	cin>>V;
	cout<<"Enter the number of Edges : ";
	cin>>E;                      //for mst, total no. of edges = total no. of vertices -1;
	
	//creating graph;
	int **graph= new int*[V];
	for(int i=0;i<V;i++)
	{
		graph[i]=new int[V];
		for(int j=0;j<V;j++)
		{
			graph[i][j]=0;
		}
	}
	
	for(int i=0;i<E;i++)
	{
		cout<<"Enter source : ";
		cin>>source;
		cout<<"Enter destination : ";
		cin>>destination;
		cout<<"Enter weight : ";
		cin>>weight;
		graph[source][destination]=weight;
		graph[destination][source]=weight;
	}
	cout<<"Matrix is : \n";
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			cout<<left<<setw(5)<<graph[i][j];
		}
		cout<<endl;
	}
	int parent[V];
	int key[V];
	bool mst[V];
	for(int i=0;i<V;i++)
	{
		key[i]=INT_MAX;
		mst[i]=false;
	}
	key[0]=0;        //setting the vale of vertex 0 as 0
	parent[0]=-1;  //setting the parent of vertex 0 as -1 as it is not having eny parent
	for(int e=0;e<V-1;e++)                  //V-1 because in mst, total edges= total vertices - 1
	{
		int u =vertex_with_min_edge_weight(key,V,mst);
		mst[u]=true;
		for(int v=0;v<V;v++)
		{
			if(graph[u][v] && mst[v]==false && graph[u][v]<key[v])
			{
				parent[v]=u;
				key[v]=graph[u][v];     //graph[u][v] is the weight	
			}
		}
	}
	
	//calculating minimum cost
	int mini_cost;
	int length = sizeof(key)/sizeof(key[0]);
	for(int i=0;i<length;i++)
	{
		mini_cost+=key[i];
	}
	
	
	
	
	
	cout<<"MST : \n";
	//printing the matrix
	cout<<left<<setw(7)<<"\nEdge : "<<left<<setw(7)<<"Weight\n";
	for(int i=1;i<V;i++)
	{
		cout<<parent[i]<<"-"<<i<<"   "<<graph[i][parent[i]]<<endl;
	}
	
	cout<<"minimum cost is : "<<mini_cost;
	cout<<endl;
	return 0;
}
