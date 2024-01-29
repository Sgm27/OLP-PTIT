#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 
int dp[55];
void init()
{
    dp[0]=dp[1]=1;
    FOR(i,2,50)
        FOR(k,1,3) 
            if (i-k>=0) dp[i]+=dp[i-k];
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        cout<<dp[n]<<"\n";	
    }    
}
