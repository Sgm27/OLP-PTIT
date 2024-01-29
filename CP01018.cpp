#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 105
const int MOD=1e9+7;
int dp[maxn][maxn],n,m;
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
            FOR(j,1,m) dp[i][j]=0;
        // dp[0][0]=1;
        FOR(i,1,n) dp[i][0]=1;
        FOR(i,1,m) dp[0][i]=1;
        FOR(i,1,n)
            FOR(j,1,m) dp[i][j]=dp[i-1][j]+dp[i][j-1], dp[i][j]%=MOD;
        cout<<dp[n][m]<<"\n";
    }
}
