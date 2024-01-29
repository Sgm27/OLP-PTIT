#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1003
vector<int> adj[maxn];
vector<pii> bridge;
int n,m,low[maxn],id[maxn],par[maxn],timer;
void reset()
{
    bridge.clear();
    timer=0;
    FOR(i,1,maxn-1) low[i]=id[i]=par[i]=0, adj[i].clear();
}
void Tarjan(int u)
{
    low[u]=id[u]=++timer;
    for (int v : adj[u])
        if (par[u]!=v)
        {
            if (id[v]) low[u]=min(low[u],id[v]);
            else
            {
                par[v]=u;
                Tarjan(v);
                low[u]=min(low[u],low[v]);
                if (low[v]==id[v]) bridge.push_back({min(u,v),max(u,v)});
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
        reset();
        FOR(i,1,m)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }	
        FOR(i,1,n) 
            if (!par[i]) par[i]=-1, Tarjan(i);
        sort(bridge.begin(),bridge.end());
        for (pii x : bridge) cout<<x.first<<" "<<x.second<<" ";
        cout<<"\n";
    }
}
