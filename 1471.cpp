#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1005
int dp[maxn][maxn],n,m,a[maxn][maxn];
void init()
{
    FOR(i,1,maxn) dp[0][i]=1e18;
    FOR(i,1,maxn) dp[i][0]=1e18;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>m;
        FOR(i,1,n)
            FOR(j,1,m) cin>>a[i][j];
        FOR(i,1,n)
            FOR(j,1,m)
                if (i==1 && j==1) dp[i][j]=a[i][j];
                else dp[i][j]=min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]})+a[i][j];
        cout<<dp[n][m]<<"\n";
    }
}
