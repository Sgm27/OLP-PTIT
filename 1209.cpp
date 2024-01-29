#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
#define maxn 105
int n,m,k,idx[maxn][maxn],r[maxn*maxn];
unordered_map<int,int> edges[maxn*maxn];
pii a[maxn*maxn];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
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
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k>>m;
    int count=0;
    FOR(i,1,n) FOR(j,1,n) idx[i][j]=++count;
    FOR(i,1,n) 
        FOR(j,1,n) 
        {
            FOR(t,0,3)
            {
                int x=i+dx[t];
                int y=j+dy[t];
                if (x>=1 && x<=n && y>=1 && y<=n) edges[idx[i][j]][idx[x][y]]=1;
            }
        }
    FOR(i,1,n*n) r[i]=i;
    FOR(i,1,m) 
    {
        int u,v,x,y;
        cin>>u>>v>>x>>y;
        edges[idx[u][v]][idx[x][y]]=0;
        edges[idx[x][y]][idx[u][v]]=0;
    }
    FOR(i,1,k) cin>>a[i].first>>a[i].second;
    int ans=0;
    FOR(i,1,n) 
        FOR(j,1,n) 
        {
            FOR(t,0,3)
            {
                int x=i+dx[t];
                int y=j+dy[t];
                if (x>=1 && x<=n && y>=1 && y<=n && edges[idx[i][j]][idx[x][y]]) Union(idx[i][j],idx[x][y]);
            }
        }
    map<int,int> mp;
    vector<int> v;
    FOR(i,1,k)
        mp[get_root(idx[a[i].first][a[i].second])]++;
    for (pii x : mp) v.push_back(x.second);
    if (v.size()<2) return cout<<0, 0;
    FOR(i,0,v.size()-2)
        FOR(j,i+1,v.size()-1) ans+=v[i]*v[j];
    cout<<ans;
}
