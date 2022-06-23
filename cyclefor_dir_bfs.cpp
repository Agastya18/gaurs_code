#include<bits/stdc++.h>
using namespace std;
void ad(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
	//adj[v].push_back(u);
}
bool iscycle(int V,vector<int> adj[])
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
	//vector<int>topo;
	int ct=0;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		ct++;
		//topo.push_back(node);
		for(auto it :adj[node])
		{
			ind[it]--;
			if(ind[it]==0)
			{
				q.push(it);
			}
		}
	}
	if(ct==V) return false;
	return true;
	//return topo;
}


int main()
{
	int V;
	cout<<"enter the vertex:";
	cin>>V;
	vector<int>adj[V];
	ad(adj,0,1);
	ad(adj,1,2);
	ad(adj,2,0);
	ad(adj,3,4);
	ad(adj,4,5);
	//ad(adj,3,1);
    int b=iscycle(V,adj);
    if(b==true)
    {
    	cout<<"cycle is present";
    }
    else
    {
    	cout<<"no cycle";
    }

}