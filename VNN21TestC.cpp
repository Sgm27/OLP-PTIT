#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
#define maxn 20
#define maxS 550
int n,a[maxn],sum,dp[maxn][maxS][maxS];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i], sum+=a[i];
    dp[0][0][0]=1;
    FOR(i,1,n)
        FOD(j,sum,0)
            FOD(k,sum,0)
            {
                if (dp[i-1][j][k]) dp[i][j][k]=1;
                if (j>=a[i] && dp[i-1][j-a[i]][k]) dp[i][j][k]=1;
                if (k>=a[i] && dp[i-1][j][k-a[i]]) dp[i][j][k]=1;
            }
    vector<int> ans;
    FOR(i,1,sum)    
        FOR(j,1,sum)    
            if (dp[n][i][j] && i==j) ans.push_back(i);
    sort(ans.begin(),ans.end());
    ans.resize(unique(ans.begin(),ans.end())-ans.begin());
    cout<<ans.size()<<"\n";
    for (int x : ans) cout<<x<<" "; 
}
