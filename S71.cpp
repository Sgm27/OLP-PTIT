#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 

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
        int n,k;
        cin>>n>>k;
        vector<int> dp(n+1);
        dp[0]=1;
        FOR(i,1,n)
            FOR(j,max(i-k,0ll),i-1)    	
                (dp[i]+=dp[j])%=MOD;
        cout<<dp[n]<<"\n";
    }
}
