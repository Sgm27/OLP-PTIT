#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 505
int n,m,a[maxn][maxn],dp[maxn][maxn];
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
        cin>>n>>m;
        int ans=0;
        FOR(i,1,n) FOR(j,1,m) cin>>a[i][j], dp[i][j]=0;
        FOR(i,1,n)
            FOR(j,1,m)
                if (a[i][j])
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1, ans=max(ans,dp[i][j]);
        cout<<ans<<"\n";
    }
}
