#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 10004
int dp[maxn];

void init()
{
    int n=maxn-4;
    fill(dp+1,dp+n+1,INF);
    dp[0]=0;
    FOR(i,1,sqrt(n))
        FOR(j,i*i,n)
            dp[j]=min(dp[j],dp[j-i*i]+1);
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
        int n; cin>>n;
        cout<<dp[n]<<"\n";
    }
}
