#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,m,k,U,V,W,f1[maxn],f2[maxn];
vector<pii> adj[maxn];
void dijkstra(int s,int f[])
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
        cin>>n>>m>>k;
        FOR(i,1,n)
        {
            f1[i]=f2[i]=INF;
            int u,v,w;
            cin>>u>>v>>w;
            if (i!=k)
            {
                adj[u].push_back({v,w});
                adj[v].push_back({u,w});
            }
            else
            {
                U=u;
                V=v;
                W=w;
            }
        }
        dijkstra(U,f1);
        dijkstra(V,f2);
        FOR(i,1,n) cout<<f1[i]<<" "; cout<<"\n";
        FOR(i,1,n) cout<<f2[i]<<" ";
        FOR(i,1,n) adj[i].clear();
    }
}
