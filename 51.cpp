#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 2003
int n,r;
struct Point{
    int x,y;
} a[maxn];
struct DSU{
    int r[maxn],n;
    DSU(int sz)
    {
        n=sz;
        FOR(i,1,n) r[i]=i;
    }
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
};
int distance(Point a,Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>r;
    FOR(i,1,n) cin>>a[i].x>>a[i].y;
    DSU dsu(n);
    int ans=n;
    FOR(i,1,n-1)
        FOR(j,i+1,n)
        {
            if (distance(a[i],a[j])<=4*r*r) 
                if (dsu.join(i,j)) ans--;
        }
    cout<<ans;
}
