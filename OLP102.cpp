#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 100005
#define maxbit 17
int n,h[maxn];
vector<pii> adj[maxn];
struct ST{
    int par,Max=0,Min=1e18;
}   p[maxn][maxbit+5];
void dfs(int u)
{
    for (pii v : adj[u])
        if (v.first!=p[u][0].par)
        {
            h[v.first]=h[u]+1;
            p[v.first][0].par=u;
            p[v.first][0].Max=v.second;
            p[v.first][0].Min=v.second;
            FOR(i,1,maxbit)
            {
                p[v.first][i].par=p[p[v.first][i-1].par][i-1].par;
                p[v.first][i].Max=max(p[v.first][i-1].Max,p[p[v.first][i-1].par][i-1].Max);
                p[v.first][i].Min=min(p[v.first][i-1].Min,p[p[v.first][i-1].par][i-1].Min);
            }
            dfs(v.first);
        }
}
pii LCA(int u,int v)
{
    int ans_min=1e18,ans_max=0;
    if (h[u]<h[v]) swap(u,v);
    int delta=h[u]-h[v];
    FOR(i,0,maxbit)
        if ((delta>>i)&1) 
        {
            ans_min=min(ans_min,p[u][i].Min);
            ans_max=max(ans_max,p[u][i].Max);
            u=p[u][i].par;
        }
    if (u==v) return {ans_min,ans_max};
    FOD(i,maxbit,0)
        if (p[u][i].par!=p[v][i].par)
        {
            ans_min=min({ans_min,p[u][i].Min,p[v][i].Min});
            ans_max=max({ans_max,p[u][i].Max,p[v][i].Max});
            u=p[u][i].par;
            v=p[v][i].par;
        }
    ans_min=min({ans_min,p[u][0].Min,p[v][0].Min});
    ans_max=max({ans_max,p[u][0].Max,p[v][0].Max});
    return {ans_min,ans_max};
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n-1)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1);
    int q; cin>>q;
    while (q--)
    {
        int u,v; 
        cin>>u>>v;
        pii ans=LCA(u,v);
        cout<<ans.first<<" "<<ans.second<<"\n";
    }
}
