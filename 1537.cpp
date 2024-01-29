#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 505
const int INF=1e18;
int n,m,a[maxn][maxn],D[maxn][maxn],sx,sy,ex,ey;
void bfs()
{
    queue<pii> Q;
    Q.push({sx,sy});
    D[sx][sy]=-1;
    while (!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();
        if (x==ex && y==ey) return;
        int idx_x=x,idx_y=y;
        idx_x--;
        while (idx_x>=1 && a[idx_x][y]==1)  
            if (D[idx_x][y]==INF) 
            {
                D[idx_x][y]=min(D[idx_x][y],D[x][y]+1);
                Q.push({idx_x,y});
                idx_x--;
            }
            else break;
        idx_x=x; idx_x++;
        while (idx_x<=n && a[idx_x][y]==1)  
            if (D[idx_x][y]==INF) 
            {
                D[idx_x][y]=min(D[idx_x][y],D[x][y]+1);
                Q.push({idx_x,y});
                idx_x++;
            }
            else break;
        idx_y--;
        while (idx_y>=1 && a[x][idx_y]==1)  
            if (D[x][idx_y]==INF) 
            {
                D[x][idx_y]=min(D[x][idx_y],D[x][y]+1);
                Q.push({x,idx_y});
                idx_y--;
            }   
            else break;
        idx_y=y; idx_y++;
        while (idx_y<=m && a[x][idx_y]==1)  
            if (D[x][idx_y]==INF) 
            {
                D[x][idx_y]=min(D[x][idx_y],D[x][y]+1);
                Q.push({x,idx_y});
                idx_y++;
            }
            else break;
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
        FOR(i,1,n)
            FOR(j,1,m) 
            {
                D[i][j]=INF;
                char c; cin>>c;
                if (c=='S') a[i][j]=1, sx=i, sy=j;
                if (c=='T') a[i][j]=1, ex=i, ey=j;
                if (c=='.') a[i][j]=1;
                if (c=='*') a[i][j]=-1;
            }   	
        bfs();
        if (D[ex][ey]<=2) cout<<"YES\n"; else cout<<"NO\n";
    }
}
