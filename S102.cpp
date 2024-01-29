#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 105
int n,a[maxn],dp[maxn*maxn];
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
        FOR(i,1,n) cin>>a[i], dp[i]=0;
        int sum=accumulate(a+1,a+1+n,0);
        if (sum & 1) 
        {
            cout<<"NO\n";
            continue;
        }
        dp[0]=1;
        sum/=2;
        FOR(i,1,n)
            FOD(j,sum,a[i])
                if (dp[j-a[i]]) dp[j]=1;
        cout<<(dp[sum] ? "YES\n" : "NO\n");
    }
}
