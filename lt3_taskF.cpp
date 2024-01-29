#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define max_bfs 1<<25
#define maxn 
int n,q;
int sx,sy,ex,ey;
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
unordered_map<int,int> hang,cot;
map<pii,int> D1,D2;
bool bfs()
{
    D1.clear(), D2.clear();
    int cnt_bfs=1;
    queue<pii> Q1,Q2;
    Q1.push({sx,sy});
    Q2.push({ex,ey});
    D1[{sx,sy}]=1, D2[{ex,ey}]=1;
    while (!Q1.empty())
    {   
        if (cnt_bfs++>max_bfs) return false;
        int x1=Q1.front().first;
        int y1=Q1.front().second;
        int x2=Q2.front().first;
        int y2=Q2.front().second;
        Q1.pop();
        Q2.pop();
        FOR(k,0,7)
        {
            int xx1=x1+dx[k];
            int yy1=y1+dy[k];
            if (D2[{xx1,yy1}]) return true;
            if (!hang[xx1] && !cot[yy1] && !D1[{xx1,yy1}])
            {
                D1[{xx1,yy1}]=1;
                Q1.push({xx1,yy1});
            }
            int xx2=x2+dx[k];
            int yy2=y2+dy[k];
            if (D1[{xx2,yy2}]) return true;
            if (!hang[xx2] && !cot[yy2] && !D2[{xx2,yy2}])
            {
                D2[{xx2,yy2}]=1;
                Q2.push({xx2,yy2});
            }
        }
    }
    return false;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    // freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,n)
    {
        int h,c;
        cin>>h>>c;
        hang[h]=1, cot[c]=1;
    }
    while (q--)
    {
        cin>>sx>>sy>>ex>>ey;
        cout<<bfs()<<"\n";
    }
}
