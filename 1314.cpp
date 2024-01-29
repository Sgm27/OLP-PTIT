#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 
vector<vector<int>> res;
int x[25];
void Try(int i,int n)
{
    if (n==0) 
    {
        vector<int> tmp(x+1,x+i);
        res.push_back(tmp);
        return;
    }
    FOD(j,x[i-1],1)
        if (n-j>=0)
        {
            x[i]=j;
            Try(i+1,n-j);
        }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
       int n; cin>>n;
       x[0]=n;
       Try(1,n); 
       for (auto v : res)
       {
            cout<<"(";
            for (int i=0;i<v.size()-1;i++) cout<<v[i]<<" ";
            cout<<v.back()<<") ";
       }
       cout<<"\n";
       res.clear();
    }   
}
