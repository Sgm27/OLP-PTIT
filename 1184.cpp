#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1005
vector<int> adj[maxn];
int n,m,s,t,visited[maxn],trace[maxn];
void dfs(int u)
{
    visited[u]=1;
    for (int v : adj[u])
        if (!visited[v]) 
        {
            trace[v]=u;
            dfs(v);
        }
}
void tracing(int u)
{
    vector<int> path;
    for(;u!=trace[u];u=trace[u]) path.push_back(u);
    path.push_back(u);
    reverse(path.begin(),path.end());
    for(int x : path) cout<<x<<" ";
    cout<<"\n";
}
signed main()
{
    // freopen("thu.inp","r",stdin);    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>m>>s>>t;
        FOR(i,1,n) trace[i]=i, visited[i]=0;
        FOR(i,1,m)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        dfs(s);
        FOR(i,1,n) adj[i].clear();
        if (visited[t]) tracing(t); else cout<<"-1\n";
    }
}
