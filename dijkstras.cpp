#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>>adj[],int u,int v,int wt)
{
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});

}
void dijkstra(int V,int src,vector<pair<int,int>>adj[])
{
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  vector<int>dist(V+1,INT_MAX);
 
  dist[src]=0;
  pq.push({0,src});
  while(!pq.empty())
  {
   int d=pq.top().first;
   int prev=pq.top().second;
   pq.pop();
   for(auto it : adj[prev])
   {
    int next=it.first;
    int nextd=it.second;
    if(dist[next]>d+nextd){
      dist[next]=dist[prev]+nextd;
      pq.push({dist[prev],next});
    }
   }
  }
  for(int i=1;i<=V;i++)
  {
    cout<<dist[i]<<" ";
    cout<<endl;
  }
}



int main()
{  int V;
    cout<<"enter the number of vertex:";
    cin>>V;

    vector<pair<int,int>>adj[V];
  addEdge(adj,0, 7, 8);  
    addEdge(adj,1, 2, 8);  
    addEdge(adj,1, 7, 11);  
    addEdge(adj,2, 3, 7);  
    addEdge(adj,2, 8, 2);  
    addEdge(adj,2, 5, 4);  
    addEdge(adj,3, 4, 9);  
    addEdge(adj,3, 5, 14);  
    addEdge(adj,4, 5, 10);  
    addEdge(adj,5, 6, 2);  
    addEdge(adj,6, 7, 1);  
  addEdge(adj,6, 8, 6);  
    addEdge(adj,7, 8, 7);  
    addEdge(adj,1, 2, 8);  
    addEdge(adj,1, 7, 11);  
    addEdge(adj,2, 3, 7);  
    addEdge(adj,2, 8, 2);  
    addEdge(adj,2, 5, 4);  
    addEdge(adj,3, 4, 9);  
    addEdge(adj,3, 5, 14);  
    addEdge(adj,4, 5, 10);  
    addEdge(adj,5, 6, 2);  
    addEdge(adj,6, 7, 1);  
    addEdge(adj,6, 8, 6);  
    addEdge(adj,7, 8, 7);  
    dijkstra( V, 0,adj);
   
    
}