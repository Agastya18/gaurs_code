#include<bits/stdc++.h>
using namespace std;
void  addEdge(vector<pair<int,int>>adj[],int u,int v,int wt)
{
	adj[u].push_back({v,wt});
	//adj[v].push_back(u);
}
void findtoposort(int node,vector<bool>&vis,stack<int>&st,vector<pair<int,int>>adj[])
{
	vis[node]=true;
	for(auto it : adj[node])
	{
		if(vis[it.first]==false)
		{
			findtoposort(it.first,vis,st,adj);
		}
	}


	
	st.push(node);
}
void short_path(int src,int V,vector<pair<int,int>>adj[])
{
  stack<int>st;
  vector<bool>vis(V,false);
  for (int i = 0; i < V; ++i)
  	{
  		if(vis[i]==false)
  		{
  			findtoposort(i,vis,st,adj);
  		}
  	}	
  	int dist[V];
  	for (int i = 0; i < V; ++i)
  	{
  		dist[i]=INT_MAX;
  	}
  	dist[src]=0;
  	while(!st.empty())
  	{
  		int node=st.top();
  		st.pop();
  		if(dist[node]!=INT_MAX)
  		{
  			for(auto it : adj[node])
  			{
  				if(dist[node]+ it.second < dist[it.first])
  				{
  					dist[it.first]=dist[node]+it.second;
  				}
  			}
  		}
  	}
  	for (int i = 0; i < V; ++i)
  	{
  	(dist[i]==INT_MAX)? cout<<"INF" : cout<<dist[i]<<" ";
  	}
  

  
}
int main()
{
	int V;
	cout<<"enter the vertex:";
	cin>>V;
	vector<pair<int,int>> adj[V];
	 addEdge(adj,0, 1, 5);
    addEdge(adj,0, 2, 3);
    addEdge(adj,1, 3, 6);
    addEdge(adj,1, 2, 2);
    addEdge(adj,2, 4, 4);
    addEdge(adj,2, 5, 2);
    addEdge(adj,2, 3, 7);
    addEdge(adj,3, 4, -1);
    addEdge(adj,4, 5, -2);
    short_path(1,V,adj);


}