#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n+1),dp(k+1,0);
        FOR(i,1,n) cin>>a[i];
        dp[0]=1;
        FOR(i,1,k)
            FOR(j,1,n)
                if (i>=a[j] && dp[i-a[j]]) 
                {
                    // cerr<<i<<" "<<a[j]<<"\n";
                    (dp[i]+=dp[i-a[j]])%=MOD;
                }
        cout<<dp[k]<<"\n";
    }
}
