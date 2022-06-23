#include<bits/stdc++.h>
using namespace std;
void ad(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);

}

bool checkforcycle(int node,int p,vector<int>&vis,vector<int>adj[])
{
  vis[node]=true;
  for(int it : adj[node])
  {
    if(vis[it]==false)
    {
      if(checkforcycle(it,node,vis,adj)) return true;
    }
     else if(it!=p) return true;
  }
  return false;
}
bool iscycle(int i,int V,vector<int>adj[])
{
  vector<int>vis(V+1,false);
  
      if(checkforcycle(i,-1,vis,adj)) return true;
    
  return false;
}

int main()
{  int V;
    cout<<"enter the number of vertex:";
    cin>>V;

    vector<int>adj[V];
    ad(adj,1,0);
    ad(adj,0,2);
    ad(adj,2,1);
    ad(adj,0,3);
    ad(adj,3,4);
    
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