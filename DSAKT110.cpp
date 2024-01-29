#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 1000006
int n,a[maxn],dp[maxn][2];
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
        cin>>n;
        FOR(i,1,n) cin>>a[i], dp[i][0]=dp[i][1]=0;
        FOR(i,1,n)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+a[i];
        }	
        cout<<max(dp[n][1],dp[n][0])<<"\n";
    }
}
