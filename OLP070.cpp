#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 10004
int n,m,id[maxn],low[maxn],par[maxn],cnt,khop,cau;
vector<int> ke[maxn];
void dfs(int u)
{
    int child=(par[u]!=-1);
    low[u]=id[u]=++cnt;
    for (int v : ke[u])
        if (par[u]!=v)
        {
            if (id[v]) low[u]=min(low[u],id[v]);
            else
            {
                par[v]=u;
                dfs(v);
                low[u]=min(low[u],low[v]);
                if (low[v]>=id[u]) child++;
                if (low[v]==id[v]) cau++;
            }
        }
    if (child>=2) khop++;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v; cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
        if (!par[i])
        {
            par[i]=-1;
            dfs(i);
        }
    cout<<khop<<" "<<cau;
}

