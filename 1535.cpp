#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 105
int n,m,a[maxn][maxn],d[maxn][maxn];
int dx[8]={-1,0,1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,1,-1};
void bfs(int i,int j)
{
    queue<pii> Q;
    Q.push({i,j});
    d[i][j]=1;
    while (!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();
        FOR(k,0,7)
        {
            int xx=x+dx[k];
            int yy=y+dy[k];
            if (xx>=1 && xx<=n && yy>=1 && yy<=m && a[xx][yy] && !d[xx][yy])
            {
                d[xx][yy]=1;
                Q.push({xx,yy});
            }
        }
    }
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
        cin>>n>>m;
        int count=0;
        FOR(i,1,n)
            FOR(j,1,m) cin>>a[i][j], d[i][j]=0;
        FOR(i,1,n)
            FOR(j,1,m)
            if (a[i][j] && !d[i][j])
            {
                bfs(i,j);
                count++;
            }
        cout<<count<<"\n";
    }    
}
