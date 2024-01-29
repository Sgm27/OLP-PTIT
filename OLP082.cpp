#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
using ld = long double;
#define maxn 105
int n,m;
struct point{
    ld x,y;
    int idx;
} p[maxn];
struct edge{
    int u,v;
    ld dis;
} e[maxn];
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
ld distance(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(edge a,edge b)
{
    return a.dis<b.dis;
}
void process()
{
    m=0;
    FOR(i,1,n-1)
        FOR(j,i+1,n)
            e[++m]={p[i].idx,p[j].idx,distance(p[i],p[j])};
    sort(e+1,e+1+m,cmp);
    DSU dsu(n);
    ld ans=0;
    int count=0;
    FOR(i,1,m)
    {
        if (dsu.join(e[i].u,e[i].v)) 
        {
            ans+=e[i].dis;
            count++;
        }
        if (count==n-1) break;
    }
    cout<<fixed<<setprecision(6)<<ans<<"\n";
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n;
        FOR(i,1,n) cin>>p[i].x>>p[i].y, p[i].idx=i;	
        process();
    }
}
