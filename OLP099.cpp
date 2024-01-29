#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
vector<int> adj[maxn];
int n,d[maxn];
void dfs(int u,int par)
{
    for (int v : adj[u])
        if (v != par)
        {
            d[v]=d[u]+1;
            dfs(v,u);
        }
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
    dfs(1,-1);
    int u=max_element(d+1,d+1+n)-d;
    memset(d,0,sizeof(d));
    dfs(u,-1);
    cout<<*max_element(d+1,d+1+n);
}
