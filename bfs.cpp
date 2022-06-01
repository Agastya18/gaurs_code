#include<bits/stdc++.h>
using namespace std;
void ad(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);

}
void bfs(vector<int>adj[],int V,int s)
{
    vector<bool>vis(V,false);
    queue<int>q;
    q.push(s);
    vis[s]=true;
    while(!q.empty())
    {
        int i=q.front();
        q.pop();
        cout<<i<<" ";
        for(int j: adj[i])
        {
             if(vis[j]==false)
       {
        q.push(j);
        vis[j]=true;
        
       }
        }
    }


}
int main()
{  int V;
    cout<<"enter the number of vertex:";
    cin>>V;

    vector<int>adj[V];
    ad(adj,0,1);
    ad(adj,0,2);
    ad(adj,2,0);
    ad(adj,2,3);
    ad(adj,3,3);
    bfs(adj,V,2);
    
}