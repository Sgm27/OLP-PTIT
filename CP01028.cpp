#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 
int a,b,x,y,n;
int calc(int x)
{
    return a*b-n*b-x*x+x*(n+b-a);
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
        cin>>a>>b>>x>>y>>n;
        if (n>=a-x+b-y) 
        {
            cout<<x*y<<"\n";
            continue;
        }
        int max_y=min(b-y,n);
        int min_y=max(0ll,n-(a-x));
        cout<<min(calc(max_y),calc(min_y))<<'\n';
    }
}
