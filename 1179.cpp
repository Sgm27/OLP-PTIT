#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1003
vector<int> adj[maxn];
int n,m,s,visited[maxn];
void dfs(int u)
{
    cout<<u<<" ";
    visited[u]=1;
    for (int v : adj[u]) 
        if (!visited[v]) dfs(v);
}
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        memset(visited,0,sizeof(visited));
        cin>>n>>m>>s;
        FOR(i,1,m) 
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(s);
        FOR(i,1,n) adj[i].clear();
        cout<<"\n";
    }    
}
