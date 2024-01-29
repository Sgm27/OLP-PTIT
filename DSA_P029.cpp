#include<iostream>
using namespace std;
using ll = long long;
#define maxn 1<<17
#define bit(n,i) ((n>>i)&1)
int n,a[17][17],dp[maxn][17];
void input()
{
    cin>>n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) cin>>a[i][j];
}
void process()
{
    for (int mask=1;mask<(1<<n);mask++)
    {
        if (__builtin_popcount(mask)==1) continue;
        else
        {
            for (int i=0;i<n;i++)
                if (bit(mask,i)) 
                {
                    dp[mask][i]=1e9;
                    int pre_mask=mask-(1<<i);
                    for (int j=0;j<n;j++)
                        if (bit(pre_mask,j)) 
                            dp[mask][i]=min(dp[mask][i],dp[pre_mask][j]+a[j][i]);
                }
        }
    }
    int ans=1e9;
    for (int i=0;i<n;i++) ans=min(ans,dp[(1<<n)-1][i]);
    cout<<ans<<"\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        input();
        process();	
    }
}
