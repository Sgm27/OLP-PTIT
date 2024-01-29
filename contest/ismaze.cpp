#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 3005
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
vector<int> adj[maxn*maxn];
int n,idx[maxn][maxn],a[maxn][maxn];
int d[maxn*maxn];
struct DSU{
    vector<int> r;
    DSU(int n)
    {
        r.resize(n*n+5);
        FOR(i,1,n*n) r[i]=i;
    }  
    int get_root(int u)
    {
        if (u==r[u]) return u;
        return r[u]=get_root(r[u]);
    }
    void Union(int u,int v)
    {
        u=get_root(u);
        v=get_root(v);
        r[u]=v;
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    int count=0;
    FOR(i,1,n)
        FOR(j,1,n)
        {
            char c; cin>>c;
            a[i][j]=c-'0';
            idx[i][j]=++count;
        }
    FOR(i,1,n)
        FOR(j,1,n)
            if (!a[i][j])
            {
                FOR(k,0,3)
                {
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if (x>=1 && x<=n && y>=1 && y<=n && !a[x][y])
                        adj[idx[i][j]].push_back(idx[x][y]);
                }
            }
    DSU dsu(n);
    FOR(i,1,n*n)
        for (int x : adj[i]) dsu.Union(x,i);
    int cc=0;
    FOR(i,1,n)
        FOR(j,1,n) 
            if (!a[i][j])
            {
                int r=dsu.get_root(idx[i][j]);
                if (!d[r])
                {
                    d[r]=1;
                    cc++;
                }
            }
    cout<<(cc==1 ? "Yes" : "No");
}
