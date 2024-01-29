#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 105
int a[maxn][maxn],n,sx,sy,ex,ey,D[maxn][maxn];
void bfs()
{
    queue<pii> Q;
    Q.push({sx,sy});
    while (!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();
        if (x==ex && y==ey) return cout<<D[x][y]<<"\n", void();
        int idx_x=x,idx_y=y;
        idx_x--;
        while (idx_x>=1 && a[idx_x][y]==0)  
            if (!D[idx_x][y]) 
            {
                D[idx_x][y]=D[x][y]+1;
                Q.push({idx_x,y});
                idx_x--;
            }
            else break;
        idx_x=x; idx_x++;
        while (idx_x<=n && a[idx_x][y]==0)  
            if (!D[idx_x][y]) 
            {
                D[idx_x][y]=D[x][y]+1;
                Q.push({idx_x,y});
                idx_x++;
            }
            else break;
        idx_y--;
        while (idx_y>=1 && a[x][idx_y]==0)  
            if (!D[x][idx_y]) 
            {
                D[x][idx_y]=D[x][y]+1;
                Q.push({x,idx_y});
                idx_y--;
            }   
            else break;
        idx_y=y; idx_y++;
        while (idx_y<=n && a[x][idx_y]==0)  
            if (!D[x][idx_y]) 
            {
                D[x][idx_y]=D[x][y]+1;
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
    int tc; tc=1;
    while (tc--)
    {
        cin>>n;
        FOR(i,1,n)
            FOR(j,1,n)
            {
                D[i][j]=0;
                char c;
                cin>>c;
                if (c=='.') a[i][j]=0;
                if (c=='X') a[i][j]=-1;
            }
        cin>>sx>>sy>>ex>>ey;
        sx++,sy++,ex++,ey++;
        bfs();
    }    
}
