#include <iostream>
#include <vector>
using namespace std;

void subsequence(int ind,vector<int>&ds,int a[],int n)
{
    if (ind >= n)
    {
        for (auto it : ds)
            cout << it << " ";
        cout << endl;
        return;
    }
    ds.push_back(a[ind]);
    subsequence(ind+1,ds,a,n);
    ds.pop_back();
    subsequence(ind+1,ds,a,n);
}

int main()
{
    int a[]={1, 2, 3};
    int n=3;
    vector<int>ds;
    subsequence(0,ds,a,n);

    return 0;
}