#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,m,dd[maxn],d[maxn];
vector<pii> adj[maxn];
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
    void join(int u,int v,int w)
    {
        int ru=get_root(u);
        int rv=get_root(v);
        if (ru==rv) return;
        adj[u].push_back({v,-w});
        adj[v].push_back({u,w});
        r[ru]=rv;
    }
};
void dfs(int u,int par)
{
    for (pii v : adj[u])
        if (v.first != par)
        {
            d[v.first]=d[u]+v.second;
            dfs(v.first,u);
        }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    while (cin>>n>>m)
    {
        FOR(i,1,n) adj[i].clear(), dd[i]=0, d[i]=0;
        vector<pii> q;
        DSU dsu(n);
        while (m--)
        {
            char type; cin>>type;
            if (type=='!')
            {
                int u,v,w;
                cin>>u>>v>>w;
                dsu.join(u,v,w);
            }
            else
            {
                int u,v;
                cin>>u>>v;
                if (dsu.get_root(u) != dsu.get_root(v)) q.push_back({0,0});
                else q.push_back({u,v});
            }
        }
        FOR(i,1,n)
            {
                int root=dsu.get_root(i);
                if (!dd[root])
                    dfs(root,-1), dd[root]=1;
            }
        for (pii x : q)
            if (!x.first && !x.second) cout<<"UNKNOWN\n";
            else cout<<d[x.first]-d[x.second]<<"\n";
    }
}
