#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1003
const int INF=1e18;
struct edges{
    int u,v,w;
} e[maxn];
int n,m,s,f[maxn];
vector<pii> adj[maxn];
void dijkstra()
{
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    f[s]=0; 
    pq.push({f[s],s});
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
                f[v]=f[u]+w;
                pq.push({f[v],v});
            }
        }
    }
    FOR(i,1,n) cout<<f[i]<<" "; cout<<"\n";
}
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>m>>s;
        FOR(i,1,n)
        {
            f[i]=INF;
            adj[i].clear();
        }
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
