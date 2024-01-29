#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 105
int n,m,k,a[maxn][maxn],b[maxn][maxn],c[maxn][maxn],sum[maxn][maxn];
void calc_prefix()
{
    FOR(i,1,n)
        FOR(j,1,m)
        {
            sum[i][j]=c[i][j];
            sum[i][j]+=sum[i-1][j];
            sum[i][j]+=sum[i][j-1];
            sum[i][j]-=sum[i-1][j-1];
        }
}
int get_sum(int a,int b,int c,int d)
{
    int Sum=sum[c][d];
    Sum-=sum[c][b-1];
    Sum-=sum[a-1][d];
    Sum+=sum[a-1][b-1];
    return Sum;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m>>k;
    FOR(i,1,n)
        FOR(j,1,m) cin>>a[i][j];
    FOR(i,1,n)
        FOR(j,1,m) cin>>b[i][j];
    FOR(i,1,n)
        FOR(j,1,m)
            if (abs(a[i][j]-b[i][j])<=k) c[i][j]=1;
    calc_prefix();
    FOR(i,1,n)
    {
        FOR(j,1,m) cout<<c[i][j]<<" ";
        cout<<"\n";
    }
    int ans=0;
    FOR(x1,1,n-1) FOR(y1,1,m-1)
        FOR(x2,x1+1,n) FOR(y2,y1+1,m)
            if (get_sum(x1,y1,x2,y2)==(x2-x1+1)*(y2-y1+1))
                ans=max(ans,(x2-x1+1)*(y2-y1+1));
    cout<<ans;
}
