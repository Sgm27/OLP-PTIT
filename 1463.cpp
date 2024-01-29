#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1005
int dp[maxn][maxn],n,v,a[maxn],c[maxn];
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
        cin>>n>>v;
        FOR(i,1,n) cin>>a[i];
        FOR(i,1,n) cin>>c[i];
        FOR(i,1,n)
            FOR(j,1,v) 
                if (j>=a[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+c[i]);
                else dp[i][j]=dp[i-1][j];
        cout<<dp[n][v]<<"\n";
    }    
}
