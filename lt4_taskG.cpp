#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1004
int cnt,low[maxn],id[maxn],n,m,In[maxn],ans;
int deg[maxn];
vector<int> ke[maxn];
vector<pair<int,int>> edge;
stack<int> st;
int res=0;
void Tarjan(int u)
{
    low[u]=id[u]=++cnt;
    st.push(u);
    for (int v : ke[u])
    {
        if (In[v]) continue;
        if (id[v]) low[u]=min(low[u],id[v]);
        else
        {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        } 
    }
    if (low[u]==id[u])
    {
        ans++;
        while (!st.empty())
        {
            int v=st.top();
            st.pop();
            In[v]=ans;
            if (v==u) break;
        }
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        ke[u].push_back(v);
        edge.push_back({u,v});
    }
    for (int i=1;i<=n;i++)
        if (!id[i]) Tarjan(i);
    for (auto x : edge)
    {
        int u=x.first;
        int v=x.second;
        if (In[u] != In[v])
            deg[In[v]]++;
    }
    for (int i=1;i<=ans;i++)
        if (deg[i]==0) res++;
    cout<<res;
}

