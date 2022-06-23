#include<bits/stdc++.h>
using namespace std;
void add_edge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);

}
void shortpath_un(vector<int>adj[],int V,int s)
{
     vector<int>vis(V,false);
   int dist[V];
   for (int i = 0; i < V; ++i)
   {
      dist[i]=INT_MAX; 
   }
   dist[s]=0;

    queue<int>q;
    q.push(s);
    vis[s]=true;
   
    while(!q.empty())
    {
        int fr=q.front();
        q.pop();
        
        for(auto j: adj[fr])
        {
             if(vis[j]==false)
       {
        vis[j]=true;
        dist[j]=dist[fr]+1;
         q.push(j);
        
       }
        }
    }
    for (int i = 0; i < V; ++i)
    {
        
        cout<<dist[i]<<" ";
    }
   

}
int main()
{  int V;
    cout<<"enter the number of vertex:";
    cin>>V;

    vector<int>adj[V];
   add_edge(adj, 0, 1);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 2);
    add_edge(adj, 1, 3);
    add_edge(adj, 2, 3);
   
shortpath_un(adj,V,0);
  
    
}