#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 25
int n,s,dp[maxn][125];
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
        cin>>n>>s;
        FOR(i,1,6) dp[1][i]=1;
        int Max=6;
        FOR(i,2,n)
        {
            FOR(j,i,Max+6)
            {
                FOR(k,1,6)
                    if (j-k>=0) dp[i][j]+=dp[i-1][j-k]; 
            }
            Max+=6;
        }
        cout<<dp[n][s]<<'\n';
    }
}
