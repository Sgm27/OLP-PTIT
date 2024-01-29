#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1003
const int INF=1e18;
struct edges{
    int u,v,w;
} e[maxn];
int n,m,f[maxn];
bool BellManFord(int s)
{
    f[s]=0;
    FOR(i,1,n)
    {
        FOR(i,1,m)
        {
            if (f[e[i].u]!=INF && f[e[i].v]>f[e[i].u]+e[i].w)
                f[e[i].v]=f[e[i].u]+e[i].w;
        }
    }
    FOR(i,1,n)
    {
        FOR(i,1,m)
        {
            if (f[e[i].u]!=INF && f[e[i].v]>f[e[i].u]+e[i].w)
                return 1;
        }
    }
    return 0;
}
signed main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>m;
        fill(f+1,f+1+n,INF);
        FOR(i,1,m)
        {
            cin>>e[i].u>>e[i].v>>e[i].w;
        }
        bool flag=false;
        FOR(i,1,n)
            if (f[i]==INF && BellManFord(i)) 
            {
                cout<<"1\n";
                flag=1;
                break;
            } 
        if (!flag) cout<<"0\n";
    }    
}
