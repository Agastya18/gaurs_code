#include<bits/stdc++.h>
using namespace std;
void ad(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
   // adj[v].push_back(u);

}

bool checkforcycle(int node,vector<int>&dfsvis,vector<int>&vis,vector<int>adj[])
{
  vis[node]=true;
  dfsvis[node]=true;
  for(int it : adj[node])
  {
    if(vis[it]==false)
    {
      if(checkforcycle(it,dfsvis,vis,adj)) return true;
    }
     else if(dfsvis[it]) return true;
  }
  dfsvis[node]=false;
  return false;
}
bool iscycle(int i,int V,vector<int>adj[])
{
  vector<int>vis(V+1,false);
  vector<int>dfsvis(V+1,false);
  
      if(checkforcycle(i,dfsvis,vis,adj)) return true;
    
  
  return false;
}

int main()
{  int V;
    cout<<"enter the number of vertex:";
    cin>>V;

    vector<int>adj[V];
    ad(adj,0,1);
    ad(adj,1,5);
    ad(adj,5,4);
    ad(adj,4,0);
    ad(adj,4,3);
    ad(adj,3,2);
    ad(adj,0,2);
    
   bool var= iscycle(0,V,adj);
   if(var)
   {
    cout<<"c";

   }
   else
   {
    cout<<"nc";
   }
    
}