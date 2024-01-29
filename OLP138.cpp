#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 1005
int n;
pii a[maxn];
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
int distance(pii a,pii b)
{
    return (b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second);
}
bool f(int x)
{
    DSU dsu(n);
    int count=n;
    FOR(i,1,n-1)
        FOR(j,i+1,n)
            if (distance(a[i],a[j])<=x) 
            {
                // if (dsu.get_root(i) != dsu.get_root(j)) return 0;
                if (dsu.join(i,j)) count--;
            }
    return count==1;
}
void process()
{
    int l=0,r=1e18;
    while (r-l>1)
    {
        // cout<<l<<" "<<r<<"\n";
        int m=(l+r)/2;
        if (f(m)) r=m;
        else l=m;
    }
    cout<<r;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i].first>>a[i].second;
    process();
}
