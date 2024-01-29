#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=1e18;
#define maxn 500005
int n,m,f[maxn],h1,s1,h2,s2,dis[4][maxn];
vector<pii> adj[maxn];
struct edge{
    int u,v,w;
} e[maxn];
void dijkstra(int s,int num)
{
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    FOR(i,1,n) f[i]=INF;
    f[s]=0; 
    pq.push({f[s],s});
    while (!pq.empty())
    {
        int du=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if (du != f[u]) continue;
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
    FOR(i,1,n) dis[num][i]=f[i];
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
        FOR(i,1,n) adj[i].clear();
        cin>>h1>>s1>>h2>>s2;
        FOR(i,1,m)
        {
            int u,v,w;
            cin>>u>>v>>w;
            e[i]={u,v,w};
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dijkstra(h1,0); 
        dijkstra(s1,1);
        dijkstra(h2,2);
        dijkstra(s2,3);
        int min_path1=dis[0][s1];
        int min_path2=dis[2][s2];
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            if (dis[0][i]+dis[1][i]==min_path1 && dis[2][i]+dis[3][i]==min_path2) 
            {
                if (dis[0][i]==dis[2][i]) ans++;
                if (i==s1 && dis[0][i]<dis[2][i]) ans++; 
                if (i==s2 && dis[0][i]>dis[2][i]) ans++;
            }
        }
        for (int i=1;i<=m;i++)
        {
            int u=e[i].u;
            int v=e[i].v;
            int w=e[i].w;
            if (dis[0][u]+w+dis[1][v]==min_path1 && dis[2][u]+w+dis[3][v]==min_path2)
                if (dis[0][u] == dis[2][u]) ans=INF;
            if (dis[0][u]+w+dis[1][v]==min_path1 && dis[2][v]+w+dis[3][u]==min_path2)
                if (dis[0][u] == dis[2][v]) ans++;
            swap(u,v);
            if (dis[0][u]+w+dis[1][v]==min_path1 && dis[2][u]+w+dis[3][v]==min_path2)
                if (dis[0][u] == dis[2][u]) ans=INF;
            if (dis[0][u]+w+dis[1][v]==min_path1 && dis[2][v]+w+dis[3][u]==min_path2)
                if (dis[0][u] == dis[2][v]) ans++;
        }
        if (ans == INF) cout<<"infinity\n";
        else cout<<ans<<"\n";
    }
}
