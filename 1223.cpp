#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
const int INF=1e18;
#define maxn 105
int n,m,d[maxn][maxn];
void floyd()
{
    FOR(k,1,n)
        FOR(u,1,n)
            FOR(v,1,n) 
                if (d[u][v]>d[u][k]+d[k][v])
                    d[u][v]=d[u][k]+d[k][v];
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
        FOR(i,1,n)
            FOR(j,1,n) d[i][j]=INF;
        FOR(i,1,m)	
        {
            int u,v;
            cin>>u>>v;
            d[u][v]=1;
        }
        floyd();
        long double ans=0;
        int count=0;
        FOR(i,1,n)
            FOR(j,1,n) 
                if (i!=j && d[i][j]!=INF) ans+=(long double)d[i][j], count++;
        cout<<fixed<<setprecision(2)<<ans/(long double)count<<"\n";
    }
}
