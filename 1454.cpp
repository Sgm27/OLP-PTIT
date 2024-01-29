#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 

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
        int n,ans=0;
        cin>>n;
        vector<int> dp(n+1,0);
        vector<int> a(n+1);
        FOR(i,1,n) cin>>a[i];
        FOR(i,1,n)
        {
            dp[i]=a[i];
            FOR(j,1,i-1)
                if (a[i]>a[j]) 
                    dp[i]=max(dp[i],dp[j]+a[i]);
            ans=max(ans,dp[i]);
        }
        cout<<ans<<"\n";  	
    }     
}
