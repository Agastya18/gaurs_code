#include <iostream>
#include <vector>
using namespace std;

void subsequence(int ind,vector<int>&ds,int s,int sum,int a[],int n)
{
    if (ind == n)
    {
        if(s==sum){
        for (auto it : ds)
            cout << it << " ";
        cout << endl;}
        return;
    }
    ds.push_back(a[ind]);
    s=s+a[ind];
    subsequence(ind+1,ds,s,sum,a,n);
    s=s-a[ind];
    ds.pop_back();
    subsequence(ind+1,ds,s,sum,a,n);
}

int main()
{
    int a[]={1, 2, 1};
    int n=3;
    int sum=2;
    vector<int>ds;
    subsequence(0,ds,0,sum,a,n);

    return 0;
}