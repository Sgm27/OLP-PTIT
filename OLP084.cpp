#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
#define maxbit 19
#define maxn 300005
int n,m,used[maxn],h[maxn];
long long W,res[maxn];
vector<pii> adj[maxn];
struct edge{
    int u,v,w,id;
} e[maxn];
struct ST{
    int Max=0,par;
} p[maxn][maxbit+5];

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
void buildMST()
{
    DSU dsu(n);
    sort(e+1,e+1+m,cmp);
    FOR(i,1,m)
    {
        if (!dsu.join(e[i].u,e[i].v)) continue;
        W+=e[i].w;
        used[e[i].id]=1;
        adj[e[i].u].push_back({e[i].v,e[i].w});
        adj[e[i].v].push_back({e[i].u,e[i].w});
    }
}
void dfs(int u)
{
    for (pii v : adj[u])
        if (v.first != p[u][0].par)
        {
            h[v.first]=h[u]+1;
            p[v.first][0].par=u;
            p[v.first][0].Max=v.second;
            FOR(i,1,maxbit)
            {
                p[v.first][i].par=p[p[v.first][i-1].par][i-1].par;
                p[v.first][i].par=max(p[v.first][i-1].Max,p[p[v.first][i-1].par][i-1].Max);
            }
            dfs(v.first);
        }
}
int LCA(int u,int v)
{
    int ans_max=0;
    if (h[u]<h[v]) swap(u,v);
    int delta=h[u]-h[v];
    FOR(i,0,maxbit)
        if ((delta>>i)&1)
        {
            ans_max=max(ans_max,p[u][i].Max);
            u=p[u][i].par;
        }
    if (u==v) return ans_max;
    FOD(i,maxbit,0)
        if (p[u][i].par != p[v][i].par)
        {
            ans_max=max(ans_max,p[u][i].Max);
            ans_max=max(ans_max,p[v][i].Max);
            u=p[u][i].par;
            v=p[v][i].par;
        }
    ans_max=max(ans_max,p[u][0].Max);
    ans_max=max(ans_max,p[v][0].Max);
    return ans_max;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR(i,1,m) cin>>e[i].u>>e[i].v>>e[i].w, e[i].id=i;
    buildMST();
    dfs(1);
    FOR(i,1,m)
    {
        if (used[e[i].id]) res[e[i].id]=W;
        else
        {
            int max_edge=LCA(e[i].u,e[i].v);
            res[e[i].id]=W-max_edge+e[i].w;
        }
    }
    FOR(i,1,m) cout<<res[i]<<"\n";
}
