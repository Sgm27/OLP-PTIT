#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1005
string s1,s2;
int dp[maxn][maxn];
void process()
{
    s1="#"+s1;
    s2="#"+s2;
    int n=s1.length()-1,m=s2.length()-1;
    FOR(i,1,n)
        FOR(j,1,m)
            if (s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    cout<<dp[n][m]<<"\n";
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
        cin>>s1>>s2;
        process();        	
    }
}
