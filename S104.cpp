#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 105
int a[maxn],dp1[maxn],dp2[maxn],n;
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
        FOR(i,1,n) cin>>a[i];
        FOR(i,1,n)
        {
            dp1[i]=a[i];
            FOR(j,1,i-1) 
                if (a[i]>a[j]) dp1[i]=max(dp1[i],dp1[j]+a[i]);
        }
        FOD(i,n,1)
        {
            dp2[i]=a[i];
            FOD(j,n,i+1)
                if (a[i]>a[j]) dp2[i]=max(dp2[i],dp2[j]+a[i]);
        }
        int ans=0;
        FOR(i,1,n)
            ans=max(ans,dp1[i]+dp2[i]-a[i]);
        cout<<ans<<"\n";
    }
}
