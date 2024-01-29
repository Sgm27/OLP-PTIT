#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 200005
int n,m;
struct edge{
    int u,v,w;
} e[maxn];
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
struct DSU{
    int r[maxn],n;
    DSU(int sz)
    {
        n=sz;
        FOR(i,1,n) r[i]=i;
    }
    int get_root(int u)
    {
        if (u==r[u]) return u;
        return r[u]=get_root(r[u]);
    }
    bool join(int u,int v)
    {
        u=get_root(u);
        v=get_root(v);
        if (u==v) return 0;
        return r[u]=v, 1;
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
        cin>>n>>m;
        FOR(i,1,m) cin>>e[i].u>>e[i].v>>e[i].w;
        sort(e+1,e+1+m,cmp);
        DSU dsu(n);
        int ans=0,count=0;
        FOR(i,1,m)
        {
            if (dsu.join(e[i].u,e[i].v)) 
            {
                ans+=e[i].w;
                count++;
            }
            if (count==n-1) break;
        } 
        cout<<ans<<"\n";
    }
}
