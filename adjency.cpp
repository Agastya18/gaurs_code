#include<bits/stdc++.h>
using namespace std;
class graph
{
public:
    map<int,list<int>>adj;
    void addadj(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    
    void printadj()
    {
        for(auto i:adj)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

};
int main()
{
    graph g;
    int n;
    cout<<"enter the number of node:";
    cin>>n;
    int m;
    cout<<"enter the edge of graph:";
    cin>>m;
    for (int i = 0; i < m; ++i)
    {
        int u,v;
        cin>>u>>v;
        g.addadj(u,v);

    }
    g.printadj();
}