#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1003
int r[maxn],n,m;
int get_root(int u)
{
    if (u==r[u]) return u;
    return r[u]=get_root(r[u]);
}
void Union(int u,int v)
{
    u=get_root(u);
    v=get_root(v);
    r[u]=v;
}
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int q;
        cin>>n>>m;
        FOR(i,1,maxn) r[i]=i;
        FOR(i,1,m) 
        {
            int u,v;
            cin>>u>>v;
            Union(u,v);
        }	
        cin>>q;
        while (q--)
        {
            int x,y;
            cin>>x>>y;
            x=get_root(x);
            y=get_root(y);
            if (x==y) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
