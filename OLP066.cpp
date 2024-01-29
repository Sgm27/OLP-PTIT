#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 100005
const int INF=1e18;
int n,m,f[maxn],g[maxn];
vector<pii> adj[maxn];
void dijkstra()
{
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    f[1]=0; 
    g[1]=1;
    pq.push({f[1],1});
    while (!pq.empty())
    {
        int du=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if (du!=f[u]) continue;
        for (pii x : adj[u])
        {
            int v=x.first;
            int w=x.second;
            if (f[v]>f[u]+w) 
            {
                g[v]=g[u];
                f[v]=f[u]+w;
                pq.push({f[v],v});
            }
            else
            if (f[v]==f[u]+w) g[v]+=g[u];
        }
    }
    cout<<f[n]<<" "<<g[n]<<"\n";
}
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    while (cin>>n>>m)
    {
        FOR(i,1,n) f[i]=INF, adj[i].clear();
        FOR(i,1,m) 
        {
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dijkstra();	
    }
}
