#include<bits/stdc++.h>
using namespace std;
void ad(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);

}

void findtoposort(int node,vector<bool>&vis,stack<int>&st,vector<int>adj[])
{
  vis[node]=true;
  for(int it : adj[node])
  {
    if(vis[it]==false)
    {
      findtoposort(it,vis,st,adj);
    }
  }
  st.push(node);
}
void toposort(int V,vector<int>adj[])
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
    vector<int>topo;
    while(!st.empty())
    {
      topo.push_back(st.top());
      //cout<<st.top()<<" ";
      st.pop();
    }
     for(auto r : topo)
     {
      cout<<r<<" ";
     }
    
}

int main()
{  int V;
    cout<<"enter the number of vertex:";
    cin>>V;

    vector<int>adj[V];
    ad(adj,5,2);
  ad(adj,5,0);
  ad(adj,4,0);
  ad(adj,4,1);
  ad(adj,2,3);
  ad(adj,3,1);
    toposort(V,adj);
    
}