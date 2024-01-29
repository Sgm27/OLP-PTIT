#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
using ld = long double;
#define maxn 10003
struct point{
    ld x,y;
} a[maxn];
ld distance(point a,point b)
{
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
struct edges{
    int u,v;
    ld w;
} e[maxn*2];
int n,num_edge,r[maxn];
bool cmp_edge(edges a,edges b)
{
    return a.w<b.w;
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
void Kruskal()
{
    sort(e+1,e+1+num_edge,cmp_edge);
    ld ans=0;
    FOR(i,1,num_edge)
    {
        int u=get_root(e[i].u);
        int v=get_root(e[i].v);
        if (join(u,v)) ans+=e[i].w;
    }
    cout<<fixed<<setprecision(6)<<ans<<"\n";
}
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n;
        num_edge=0;
        FOR(i,1,n) cin>>a[i].x>>a[i].y, r[i]=i;
        FOR(i,1,n-1)
            FOR(j,i+1,n)
            {
                ++num_edge;
                e[num_edge]={i,j,distance(a[i],a[j])};
            }
        Kruskal();
    }    
}
