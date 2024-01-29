#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1003
int n,m,color[maxn],visited[maxn];
vector<int> adj[maxn];
void reset(int n)
{
    FOR(i,1,n) color[i]=0, adj[i].clear();
    color[0]=2;
}
bool dfs(int u,int par)
{
    color[u]=3-color[par];
    for (int v : adj[u])
        if (!color[v]) 
        {
            if (!dfs(v,u)) return false;
        }
        else if (color[v]==color[u]) return false;
    return true;
}
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        bool flag=true;
        cin>>n>>m;
        reset(n);
        FOR(i,1,m)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }	
        FOR(i,1,n)
            if (!color[i])
            {
                if (!dfs(i,0)) 
                {
                    flag=false;
                    break;
                }
            }
        if (flag) cout<<"YES\n"; else cout<<"NO\n";
    }
}
