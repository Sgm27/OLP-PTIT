#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1005
const int MOD=1e9+7;
int dp[maxn*105],a[maxn];
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
        memset(dp,0,sizeof(dp));
        int n,s;
        cin>>n>>s;
        FOR(i,1,n) cin>>a[i];
        dp[0]=1;
        FOR(i,1,s)
            FOR(j,1,n)
                if (i>=a[j]) dp[i]+=dp[i-a[j]], dp[i]%=MOD;
        cout<<dp[s]<<"\n";
    }
}
