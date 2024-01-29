#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
const int INF=1e18;
#define maxn 505
int n,m,f[maxn*maxn],a[maxn][maxn],idx[maxn][maxn];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
vector<pii> adj[maxn*maxn];
void dijkstra(int s)
{
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    f[s]=a[1][1]; 
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
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>m;
        FOR(i,1,n*m) f[i]=INF, adj[i].clear();
        int count=0;
        FOR(i,1,n) 
            FOR(j,1,m) 
            {
                cin>>a[i][j];
                idx[i][j]=++count;
            }
        FOR(i,1,n)
            FOR(j,1,m)
            {
                FOR(k,0,3)
                {
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if (x>=1 && x<=n && y>=1 && y<=m) 
                        adj[idx[i][j]].push_back({idx[x][y],a[x][y]});
                }
            }
        dijkstra(1);
        cout<<f[n*m]<<"\n";
    }
}
