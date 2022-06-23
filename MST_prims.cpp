#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>>adj[],int u,int v,int wt)
{
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});

}

void mst_prims(vector<pair<int,int>>adj[],int V,int src)
{
  bool mst[V];
  int parent[V];
  int key_weight[V];
  for (int i = 0; i < V; ++i)
  {
    mst[i]=false;
    parent[i]=-1;
    key_weight[i]=INT_MAX;
  }
   key_weight[0]=src;
   parent[0]=-1;
   for (int i = 0; i < V-1; ++i)
    {
      int min=INT_MAX,u;
      for (int j = 0; j < V; ++j)
      {
        if(mst[j]==false and key_weight[j]<min)
        {
          min=key_weight[j],u=j;

        }

      }
      mst[u]=true;
      for(auto it : adj[u])
      {
        int v = it.first;
        int wt=it.second;
        if(mst[v]==false and wt < key_weight[v])
        {
          parent[v]=u,key_weight[v]=wt;
        }

      }
    } 
    for (int i = 1; i < V; ++i)
    {
      cout<<parent[i]<<" - "<<i<<endl;
    }
}



int main()
{  int V;
    cout<<"enter the number of vertex:";
    cin>>V;

    vector<pair<int,int>>adj[V];
 
    addEdge(adj,0, 1, 2);  
    addEdge(adj,0, 3, 6);  
    addEdge(adj,1, 0, 2);  
    addEdge(adj,1, 2, 3);  
    addEdge(adj,1, 3, 8);  
    addEdge(adj,1, 4, 5);  
    addEdge(adj,2, 1, 3);  
    addEdge(adj,2, 4, 7);  
    addEdge(adj,3, 0, 6);  
    addEdge(adj,3, 1, 8); 
    addEdge(adj,4, 1, 5);  
    addEdge(adj,4, 2, 7);
    mst_prims(adj,V,0);
     
   
    
}