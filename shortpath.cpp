#include<bits/stdc++.h>
using namespace std;
void add_edge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);

}
vector<int> shortpath_un(vector<int>adj[],int V,int s,int d)
{
    vector<bool>vis(V,false);
    vector<int>p;
    queue<int>q;
    q.push(s);
    p[s]=-1;
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
        p[j]=fr;
         q.push(j);
        
       }
        }
    }
    vector<int>ans;
    int curr=d;
    ans.push_back(d);
    while(curr != s)
    {
        curr=p[curr];
        ans.push_back(curr);
    }
    reverse(ans.begin(), ans.end());
 return ans;

}
int main()
{  int V;
    cout<<"enter the number of vertex:";
    cin>>V;

    vector<int>adj[V];
   add_edge(adj, 0, 1);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 2);
    add_edge(adj, 3, 4);
    add_edge(adj, 3, 7);
    add_edge(adj, 4, 5);
    add_edge(adj, 4, 6);
    add_edge(adj, 4, 7);
    add_edge(adj, 5, 6);
    add_edge(adj, 6, 7);
vector<int>res=shortpath_un(adj,V,0,7);
  for(auto it : res)
  {
    cout<<it<<" ";
  }
    
}
