#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1003
vector<int> adj[maxn],joint;
int n,m,low[maxn],id[maxn],par[maxn],timer;
void reset()
{
    joint.clear();
    timer=0;
    FOR(i,1,maxn-1) low[i]=id[i]=par[i]=0, adj[i].clear();
}
void Tarjan(int u)
{
    int child=(par[u]!=-1);
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
                if (low[v]>=id[u]) child++;
            }
        }
    if (child>=2) joint.push_back(u);
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
        sort(joint.begin(),joint.end());
        for (int u : joint) cout<<u<<" ";
        cout<<"\n";
    }
}
