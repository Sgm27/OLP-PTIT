#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 300005
int n,m,timer;
vector<int> adj[maxn];
set<pii> bridge;
int low[maxn],id[maxn],par[maxn];
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
void dfs(int u)
{
    low[u]=id[u]=++timer;
    for (int v : adj[u])
        if (par[u]!=v)
        {
            if (id[v]) low[u]=min(low[u],id[v]);
            else
            {
                par[v]=u;
                dfs(v);
                low[u]=min(low[u],low[v]);
                if (low[v]==id[v]) 
                {
                    cerr<<u<<" "<<v<<"\n";
                    bridge.insert({min(u,v),max(u,v)});
                }
            }
        }
}
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
void process()
{
    // cerr<<"here";
    DSU dsu(n);
    cerr<<"here";
    int count=0;
    for (int i=1;i<=m;i++)
    {
        int u=e[i].u;
        int v=e[i].v;
        if (bridge.count({min(u,v),max(u,v)})) 
        {
            bool x=dsu.join(u,v);
            count++;
        }
    }
    sort(e+1,e+1+m,cmp);
    for (int i=1;i<=m;i++)
    {
        int u=e[i].u;
        int v=e[i].v;
        if (bridge.count({min(u,v),max(u,v)}))  continue;
        if (dsu.join(u,v)) count++;
    }
    cout<<m-count<<"\n";
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
        cin>>n>>m;
        timer=0;
        FOR(i,1,n) adj[i].clear(), bridge.clear(), par[i]=0, low[i]=id[i]=0;
        FOR(i,1,m)
        {
            int u,v,w;
            cin>>u>>v>>w;
            e[i]={u,v,w};
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int check=0;
        for (int i=1;i<=n;i++)
            if (!par[i])
            {
                check++;
                if (check>=2) break;
                par[i]=-1;
                dfs(i);
            }
        if (check>=2) 
        {
            cout<<"-1\n";
            continue;
        }
        process();
    }
}
