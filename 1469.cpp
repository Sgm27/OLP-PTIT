#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 10005
int dp[maxn];
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
        int n; cin>>n;
        fill(dp+1,dp+1+n,1e18);
        FOR(i,1,sqrt(n))
            FOR(j,1,n)
                if (j>=i*i) dp[j]=min(dp[j],dp[j-i*i]+1);
        cout<<dp[n]<<"\n";
    }
}
