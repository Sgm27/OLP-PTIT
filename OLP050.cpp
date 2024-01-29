#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 
int n,m,ans;
struct DSU{
    vector<int> r,sz;
    DSU(int n)
    {
        r.resize(n+1);
        sz.resize(n+1);
        FOR(i,1,n) r[i]=i, sz[i]=1;
    }  
    int get_root(int u)
    {
        if (u==r[u]) return u;
        return r[u]=get_root(r[u]);
    }
    void Union(int u,int v)
    {
        u=get_root(u);
        v=get_root(v);
        if (u==v) return;
        if (sz[u]<sz[v]) swap(u,v);
        sz[u]+=sz[v];
        ans=max(ans,sz[u]);
        r[v]=u;
    }
};
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
        ans=0;
        cin>>n>>m;
        DSU dsu(n);
        FOR(i,1,m)
        {
            int u,v;
            cin>>u>>v;
            dsu.Union(u,v);
        }
        cout<<ans<<"\n";
    }
}
