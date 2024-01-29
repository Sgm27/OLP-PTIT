#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 400005
unordered_map<int,int> dp[maxn];
int a[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,3*k)
    {
        int tmp=a[i];
        if (i%3==2) tmp*=-1;
        dp[i][i]=dp[i-1][i-1]+tmp;
        FOR(j,i+1,n)
        {
            int tmp=a[j];
            if (i%3==2) tmp*=-1;
            dp[j][i]=max(dp[j-1][i-1]+tmp,dp[j-1][i]);
        }
    }
    cout<<dp[n][3*k];
}
