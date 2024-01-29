#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 105
string s1,s2,s3;
int dp[maxn][maxn][maxn],n,m,k;
void process()
{
    s1="#"+s1;
    s2="#"+s2;
    s3="#"+s3;
    FOR(i,1,n)
        FOR(j,1,m)
            FOR(t,1,k)
                if (s1[i]==s2[j] && s1[i]==s3[t]) 
                    dp[i][j][t]=dp[i-1][j-1][t-1]+1;
                else dp[i][j][t]=max({dp[i][j][t-1],dp[i-1][j][t],dp[i][j-1][t]});
    cout<<dp[n][m][k]<<"\n";
}
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
        cin>>n>>m>>k;
        cin>>s1>>s2>>s3;
        process();        	
    }
}
