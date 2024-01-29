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
bool Union(int u,int v)
{
    u=get_root(u);
    v=get_root(v);
    if (u==v) return 1;
    return r[u]=v, 0;
}
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        bool flag=0;
        cin>>n>>m;	
        FOR(i,1,n) r[i]=i;
        FOR(i,1,m)
        {
            int u,v;
            cin>>u>>v;
            if (Union(u,v)) flag=true;
        }
        if (flag) cout<<"YES\n"; else cout<<"NO\n";
    }
}
