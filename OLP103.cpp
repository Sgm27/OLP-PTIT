#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,d1[maxn],d2[maxn],ans,cnt;
vector<int> adj[maxn];
void dfs(int u,int par)
{
    for (int v : adj[u])
        if (v != par)
        {
            dfs(v,u);
            if (d1[v]+1>d1[u])
            {
                d2[u]=d1[u];
                d1[u]=d1[v]+1;
            }
            else
            if (d1[v]+1>d2[u]) 
                d2[u]=d1[v]+1;
        }
    if (d1[u]+d2[u]>ans) 
    {
        ans=d1[u]+d2[u];
        cnt=1;
    }
    else 
    if (d1[u]+d2[u]==ans)
        cnt++;
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
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FOR(i,1,n)
    {
        memset(d1,0,sizeof(d1));
        memset(d2,0,sizeof(d2));
        dfs(i,-1);
    }
    cout<<ans<<" "<<cnt;
}
