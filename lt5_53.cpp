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
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
void process()
{
    DSU dsu(n);
    sort(e+1,e+1+m,cmp);
    int ans=0;
    FOR(i,1,m)
    {
        int u=e[i].u;
        int v=e[i].v;
        if (dsu.join(u,v)) ans+=e[i].w;
    }
    cout<<ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR(i,1,m)
    {
        e[i].u=0;
        cin>>e[i].v>>e[i].w;
    }
    FOR(i,1,n)
    {
        m++;
        int x; cin>>x;
        if (i != n)
            e[m]={i,i+1,x};
        else
            e[m]={1,n,x};
    }
    process();
}
