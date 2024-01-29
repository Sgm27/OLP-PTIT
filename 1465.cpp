#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1005
int dp[maxn];
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
        int n,x,y,z;	
        cin>>n>>x>>y>>z;
        fill(dp+1,dp+2+n,9e18);
        dp[1]=x;
        FOR(i,2,n)
            if (i%2==0) 
                dp[i]=min({dp[i-1]+x,dp[i/2]+z,dp[i+1]+y});
            else dp[i]=min({dp[i-1]+x,dp[i+1]+y,dp[(i+1)/2]+z+y});
        cout<<dp[n]<<"\n";
    }
}
