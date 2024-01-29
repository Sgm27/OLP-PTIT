#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define bit(i,n) ((n>>i)&1)
#define pii pair<int,int>
#define maxn 1<<20
int a[20][20],n;
vector<vector<int>> dp;
void process()
{
    dp.clear();
    dp.resize(n,vector<int>(1<<n,0));
    for (int i=0;i<n;i++)   
    {
        if (i==0) 
        {
            for (int j=0;j<n;j++) dp[i][1<<j]=a[j][i];
            continue;
        }
        for (int mask=1;mask<(1<<n);mask++)
            if (__builtin_popcount(mask)==i+1)
            {
                for (int j=0;j<n;j++)
                if (bit(j,mask))
                {
                    int pre_mask=mask-(1<<j);
                    dp[i][mask]=max(dp[i][mask],dp[i-1][pre_mask]+a[j][i]);
                }
            }
    }
    int ans=0;
    for (int i=1;i<(1<<n);i++)
        ans=max(ans,dp[n-1][i]);
    cout<<ans<<"\n";
}
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
        cin>>n;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++) cin>>a[i][j];
        process();
    }
}
