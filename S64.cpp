#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 1005
int dp[maxn][maxn];
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
        string s1,s2;
        cin>>s1>>s2;
        s1=" "+s1, s2=" "+s2;
        FOR(i,1,s1.length()-1)
            FOR(j,1,s2.length()-1)
                if (s1[i]==s2[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        cout<<dp[s1.length()-1][s2.length()-1]<<"\n";
    }
}
