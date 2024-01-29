#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 25005
int C,n,dp[maxn],a[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>C>>n;
    FOR(i,1,n) cin>>a[i];
    int ans=0;
    dp[0]=1;
    FOR(i,1,n)
        FOD(j,C,a[i]) 
            if (dp[j-a[i]]) dp[j]=1, ans=max(ans,j);
    cout<<ans;

}
