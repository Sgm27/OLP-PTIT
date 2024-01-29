#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1005
const int MOD=1e9+7;
int dp[maxn][maxn];
void init()
{
    int N=1000;
    FOR(i,1,N) dp[i][i]=1, dp[0][i]=1;
    FOR(i,1,N)
        FOR(k,1,i)
            if (!dp[k][i]) dp[k][i]=(dp[k-1][i-1]+dp[k][i-1])%MOD;
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
        int n,k;
        cin>>n>>k;
        cout<<dp[k][n]<<"\n";
    }
}
