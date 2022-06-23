#include<bits/stdc++.h>
using namespace std;
void ad(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);

}

void dfsrec(vector<int>adj[],int s,vector<bool>&vis)
{
    
    cout<<s<<" ";
    vis[s]=true;
    for(int u :adj[s])
    {
      if(vis[u]==false)
      {
        dfsrec(adj,u,vis);
      }
    }
}
void dfs(vector<int>adj[],int V,int s)
{
  vector<bool>vis(V,false);
  
     dfsrec(adj,s,vis);
   
  }
 

int main()
{  int V;
    cout<<"enter the number of vertex:";
    cin>>V;

    vector<int>adj[V];
    ad(adj,0,1);
    ad(adj,0,2);
    ad(adj,1,2);
    ad(adj,2,0);
    ad(adj,2,3);
    ad(adj,3,3);
    dfs(adj,V,2);
    
}