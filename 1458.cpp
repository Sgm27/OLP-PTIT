#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 
const int MOD=1e9+7;
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
        vector<int> dp(n+1,0);
        dp[0]=1;
        FOR(i,1,n)
            FOR(j,1,k) 
                if (i-j>=0) dp[i]+=dp[i-j], dp[i]%=MOD;
        cout<<dp[n]<<"\n";
    }
}
