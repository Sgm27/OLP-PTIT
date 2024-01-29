#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1005
int n,m,dist[maxn];
vector<pii> adj[maxn];

int Prim(int s)
{
    int ans=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dist[s]=0;
    pq.push({dist[s],s});
    while (!pq.empty())
    {
        int CurDis=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if (CurDis!=dist[u]) continue;
        ans+=dist[u];
        dist[u]=-1e18;
        for (pii x : adj[u])
        {
            int v=x.first;
            int c=x.second;
            if (dist[v]>c) dist[v]=c, pq.push({dist[v],v});
        }
    }
    return ans;
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
        FOR(i,1,n) dist[i]=1e18, adj[i].clear();
        FOR(i,1,m)
        {
            int u,v,c;
            cin>>u>>v>>c;
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }	
        cout<<Prim(1)<<"\n";
    }
}
