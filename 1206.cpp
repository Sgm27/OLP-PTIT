#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 105
int n,m,visited[maxn],cnt,flag;
vector<int> adj[maxn];
void dfs(int u)
{
    if (flag) return;
    for (int v : adj[u])
        if(!visited[v])
        {
            cnt++;
            visited[v]=1;
            if (cnt==n) return flag=1, void();
            else dfs(v);
            visited[v]=0;
            cnt--;
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
        flag=0;
        cin>>n>>m;
        FOR(i,1,n) adj[i].clear();
        FOR(i,1,m) 
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        FOR(i,1,n)
        {
            cnt=1;
            memset(visited,0,sizeof(visited));
            visited[i]=1;
            dfs(i);
            if (flag) break;
        }
        cout<<flag<<"\n";
    }
}
