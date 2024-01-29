#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 25
int n,m,a[maxn][maxn],d[maxn][maxn],ans[maxn][maxn];
bool check;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
vector<pii> v;
void bfs(int i,int j)
{
    queue<pii> Q;
    Q.push({i,j});
    if (i==1 || i==n || j==1 || j==m) check=true;
    d[i][j]=1;
    while (!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();
        v.push_back({x,y});
        FOR(k,0,3)
        {
            int xx=x+dx[k];
            int yy=y+dy[k];
            if (xx>=1 && xx<=n && yy>=1 && yy<=m && a[xx][yy] && !d[xx][yy])
            {
                Q.push({xx,yy});
                d[xx][yy]=1;
                if (xx==1 || xx==n || yy==1 || yy==m) check=true;
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
        FOR(i,1,n)
            FOR(j,1,m) 
            {
                d[i][j]=0;
                char c;
                cin>>c;
                if (c=='X') a[i][j]=0;
                else a[i][j]=1;
                ans[i][j]=a[i][j];
            }
        FOR(i,1,n)
            FOR(j,1,m)
                if (a[i][j] && !d[i][j])
                {
                    check=false;
                    bfs(i,j);
                    if (!check)
                    {
                        for (pii k : v) 
                        {
                            int x=k.first;
                            int y=k.second;
                            ans[x][y]=0;
                        }
                    }
                    v.clear();
                }
        FOR(i,1,n)
        {
            FOR(j,1,m) 
                if (ans[i][j]) cout<<"O "; else cout<<"X ";
            cout<<"\n";
        }
    }
}
