#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
int n,m,dp[1000006];
struct Array{
    int val,id;
};
bool cmp(Array a,Array b)
{
    if (a.val != b.val) return a.val<b.val;
    return a.id<b.id;
}
vector<vector<Array>> a,hang,cot;
vector<vector<int>> adj;
struct DSU{
    int n;
    vector<int> r;
    DSU(int sz)
    {
        n=sz;
        r.resize(n);
        FOR(i,1,n) r[i]=i;
    }
    int get_root(int u)
    {
        if (u==r[u]) return u;
        return r[u]=get_root(r[u]);
    }
    void join(int u,int v)
    {
        u=get_root(u);
        v=get_root(v);
        if (u==v) return;
        return r[u]=v, void();
    }
    void add_edge(int u,int v)
    {
        u=get_root(u);
        v=get_root(v);
        if (u != v)
            adj[u].push_back(v);
    }
};
int dfs(int u)
{
    if (dp[u]) return dp[u];
    for (int v : adj[u])
    {
        dp[v]=dfs(v);
        dp[u]=max(dp[u],dp[v]+1);
    }
    return dp[u];
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    DSU dsu(n*m+5);
    a.resize(n+1,vector<Array>(m+1));
    adj.resize(n*m+1);
    hang.resize(n+1), cot.resize(m+1);
    int idx=0;
    FOR(i,1,n)
        FOR(j,1,m) 
        {
            cin>>a[i][j].val;
            a[i][j].id=++idx;
            hang[i].push_back(a[i][j]);
            cot[j].push_back(a[i][j]);
        }
    FOR(i,1,n) sort(hang[i].begin(),hang[i].end(),cmp);
    FOR(i,1,m) sort(cot[i].begin(),cot[i].end(),cmp);
    for (int i=1;i<=n;i++)
        for (int j=0;j<hang[i].size()-1;j++) 
            if (hang[i][j].val==hang[i][j+1].val) dsu.join(hang[i][j].id,hang[i][j+1].id);
    for (int i=1;i<=m;i++)
        for (int j=0;j<cot[i].size()-1;j++)
            if (cot[i][j].val==cot[i][j+1].val) dsu.join(cot[i][j].id,cot[i][j+1].id);
                
    for (int i=1;i<=n;i++)
        for (int j=0;j<hang[i].size()-1;j++) 
            if (hang[i][j].val != hang[i][j+1].val) dsu.add_edge(hang[i][j].id,hang[i][j+1].id);
               
    for (int i=1;i<=m;i++)
        for (int j=0;j<cot[i].size()-1;j++)
            if (cot[i][j].val != cot[i][j+1].val) dsu.add_edge(cot[i][j].id,cot[i][j+1].id);

    int ans=0;
    FOR(i,1,n*m) ans=max(ans,dfs(i));
    cout<<ans+1;
    cerr<<"\n"<<TIME;
}
