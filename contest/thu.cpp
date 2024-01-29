#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 1000006
int dp[maxn],n,k;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    dp[1]=1, dp[2]=2;
    FOR(i,3,maxn-6) dp[i]=(3*dp[i-1]-dp[i-2]+k*k)%k;
    // FOR(i,1,10) cout<<dp[i]<<" ";
    cout<<dp[(2*n-4)/2+1];
}
