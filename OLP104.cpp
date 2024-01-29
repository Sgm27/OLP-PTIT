#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 200005
int n,a[maxn],timer;
struct edge{
    int u,v,w;
} e[maxn];
int sz[maxn],p[maxn],depth[maxn],head[maxn],pos[maxn],d[maxn];
int out[maxn],f[maxn];
vector<pii> adj[maxn];
void dfs(int u)
{
    sz[u]=1;
    int idv= 0;
    int maxSize=0;
    for (int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i].first, w=adj[u][i].second;
        if (v==p[u]) continue;
        depth[v]=depth[u]+1;
        p[v]=u;
        dfs(v);
        sz[u]+=sz[v];
        if (sz[v] > maxSize) maxSize=sz[v], idv = i;
    }
    swap(adj[u][0],adj[u][idv]);
}
void hld(int u)
{
    pos[u]=++timer;
    for (pii it : adj[u])
    {
        int v=it.first, w=it.second;
        if (p[v]==u)
        {
            if (2*sz[v] >= sz[u]) head[v]=head[u], d[v]=d[u];
            else head[v]=v, d[v]=d[u]+1;
            hld(v);
        }
    }
    out[u]=timer;
}
int t[maxn*4];
void update(int id,int l,int r,int p,int val)
{
    if (l>p || r<p) return;
    if (l==r) 
        return t[id]=val ,void();
    int m=(l+r)/2;
    update(id*2,l,m,p,val);
    update(id*2+1,m+1,r,p,val);
    t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id,int l,int r,int u,int v)
{
    if (u>v || r<u || l>v) return 0;
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    return max(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
void query(int u,int v)
{
    int ans=0;
    for (; head[u] != head[v];v = p[head[v]])
    {
        if (d[head[u]]>d[head[v]]) swap(u,v);
        ans=max(ans,get(1,1,n,pos[head[v]],pos[v]-1));
        ans=max(ans,f[head[v]]);
    }
    if (depth[u]>depth[v]) swap(u,v);
    ans=max(ans,get(1,1,n,pos[u],pos[v]-1));
    cout<<ans<<"\n";
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc=1;
    while (tc--)
    {
        cin>>n;
        FOR(i,1,n-1)
        {
            int u,v,w;
            cin>>u>>v>>w;
            e[i]={u,v,w};
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dfs(1);
        head[1]=1;
        hld(1);
        FOR(i,1,n-1) 
        {
            int u=e[i].u, v=e[i].v, w=e[i].w;
            if (depth[u] > depth[v]) swap(u,v);
            if (d[u] == d[v]) update(1,1,n,pos[u],w);
            else f[v]=w;
        }
        int qr; cin>>qr;
        while (qr--)
        {
            string q; cin>>q;
            if (q=="DONE") break;
            if (q=="QUERY")
            {
                int u,v;
                cin>>u>>v;
                query(u,v);
            }
            else
            {
                int x,w;
                cin>> x >> w;
                e[x].w=w;
                int u=e[x].u, v=e[x].v;
                if (depth[u]>depth[v]) swap(u,v);
                if (d[u] == d[v]) update(1,1,n,pos[u],w);
                else f[v]=w;
            }
        } 	
    }
}
