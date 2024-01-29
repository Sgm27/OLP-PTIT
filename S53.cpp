#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define ld long double
const int MOD=1e9+7,INF=9e18;
#define maxn 505
int n,dp[maxn];
ld a[maxn],b[maxn];
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
        FOR(i,1,n) cin>>a[i]>>b[i];
        FOR(i,1,n)
        {
            dp[i]=1;
            FOR(j,1,i-1)
                if (a[i]>a[j] && b[i]<b[j]) dp[i]=max(dp[i],dp[j]+1);
        }
        cout<<*max_element(dp+1,dp+1+n)<<"\n";
    }
}
