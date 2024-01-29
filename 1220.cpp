#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
const int INF=1e18;
#define maxn 103
int n,m,q,f[maxn][maxn];
void floyd()
{
    FOR(k,1,n)
        FOR(u,1,n)
            FOR(v,1,n) 
                if (f[u][v]>f[u][k]+f[k][v]) f[u][v]=f[u][k]+f[k][v];
}
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR(i,1,n)
        FOR(j,1,n) f[i][j]=INF;
    FOR(i,1,m) 
    {
        int u,v,w;
        cin>>u>>v>>w;
        f[u][v]=min(f[u][v],w);
        f[v][u]=min(f[v][u],w);
    }
    floyd();
    cin>>q;
    while (q--)
    {
        int u,v;
        cin>>u>>v;
        if (u!=v) cout<<f[u][v]<<"\n"; else cout<<"0\n";
    }
}
