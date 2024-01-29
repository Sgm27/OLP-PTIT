#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 50005
const int MOD=1e9+7;
int n,a[maxn],dp[maxn];
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
        int s=0;
        cin>>n;
        FOR(i,1,n) cin>>a[i], dp[i]=0, s+=a[i];
        sort(a+1,a+1+n);
        dp[0]=1;
        FOR(i,1,n)
        {
            FOR(j,1,n)
                if (i-a[j]>=0) (dp[i]+=dp[i-a[j]])%=MOD;
        }
        cout<<dp[n]<<"\n";
    }
}
