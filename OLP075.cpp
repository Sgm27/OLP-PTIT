#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+9,INF=9e18;
#define maxn 1003
int n,m,k;
int dp[maxn][maxn][12],a[maxn],b[maxn],pre[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m>>k;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,m) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    FOR(i,1,n) dp[i][0][0]=1;
    FOR(j,1,m) dp[0][j][0]=1;
    FOR(i,1,n)
        FOR(j,1,m) dp[i][j][0]=1; 
    FOR(kk,1,k)
        FOR(i,1,n)
        {
            FOR(j,1,m) pre[j]=pre[j-1]+dp[i-1][j][kk-1];
            // if (i==4 && kk==3)
            // {
            //     FOR(j,1,m) cout<<pre[j]<<" ";
            //     cout<<"\n";
            // }
            FOR(j,1,m)
                {
                    if (a[i]>b[j]) 
                    {
                        if (i==1 || j==1) (dp[i][j][kk]+=dp[i-1][j-1][kk-1])%=MOD;
                        else (dp[i][j][kk]+=pre[j-1])%=MOD;
                    }
                    else dp[i][j][kk]=0;
                }
        }
    // cout<<dp[4][4][3]<<"\n";
    int ans=0;
    FOR(i,1,n)
        FOR(j,1,m) 
        {
            (ans+=dp[i][j][k])%=MOD;
            // if (dp[i][j][k]) cerr<<i<<" "<<j<<" "<<dp[i][j][k]<<"\n";
            // cout<<i<<" "<<j<<" "<<dp[i][j][k]<<"\n";
        }
    // cout<<dp[4][4][3]<<"\n";
    // cout<<dp[n][m][k];
    cout<<ans<<"\n";
}
