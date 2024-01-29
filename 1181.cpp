#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1005
vector<int> adj[maxn];
int n,m,s,visited[maxn];
void bfs(int i)
{
    FOR(i,1,n) visited[i]=0;
    queue<int> Q;
    Q.push(i);
    visited[i]=1;
    cout<<i<<" ";
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for (int v : adj[u])
            if (!visited[v]) 
            {
                cout<<v<<" ";
                visited[v]=1;
                Q.push(v);
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
        cin>>n>>m>>s;	
        FOR(i,1,m) 
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfs(s);
        FOR(i,1,n) adj[i].clear();
        cout<<"\n";
    }
}
