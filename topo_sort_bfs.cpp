#include<bits/stdc++.h>
using namespace std;
void ad(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
	//adj[v].push_back(u);
}
vector<int> toposort(int V,vector<int> adj[])
{
	vector<int>ind(V,0);
	queue<int>q;
	for (int i = 0; i < V; ++i)
	{
		for(auto it : adj[i])
		{
			ind[it]++;
		}
	}
	for (int i = 0; i < V; ++i)
	{
		if(ind[i]==0)
		{
			q.push(i);
		}
	}
	vector<int>topo;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		topo.push_back(node);
		for(auto it :adj[node])
		{
			ind[it]--;
			if(ind[it]==0)
			{
				q.push(it);
			}
		}
	}
	return topo;
}


int main()
{
	int V;
	cout<<"enter the vertex:";
	cin>>V;
	vector<int>adj[V];
	ad(adj,5,2);
	ad(adj,5,0);
	ad(adj,4,0);
	ad(adj,4,1);
	ad(adj,2,3);
	ad(adj,3,1);

vector<int> res=toposort(V,adj);
for(auto i : res )
{
	cout<<i<<" ";
}
}