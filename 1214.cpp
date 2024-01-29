#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1005
struct edges{
    int u,v,w;
    void input()
    {
        cin>>u>>v>>w;
    }
} e[maxn];
bool cmp(edges a,edges b)
{
    return a.w<b.w;
}
int n,m,r[maxn];
int get_root(int u)
{
    if (u==r[u]) return u;
    return r[u]=get_root(r[u]);
}
bool join(int u,int v)
{
    u=get_root(u);
    v=get_root(v);
    if (u==v) return 0;
    return r[u]=v, 1;
}
void Kruskal()
{
    FOR(i,1,n) r[i]=i;
    sort(e+1,e+1+m,cmp);
    int ans=0;
    FOR(i,1,m)
    {
        int u=get_root(e[i].u);
        int v=get_root(e[i].v);
        if (join(u,v)) ans+=e[i].w;
    }
    cout<<ans<<"\n";
}
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>m;
        FOR(i,1,m) e[i].input();
        Kruskal();
    }
}
