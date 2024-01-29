#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1005
int dp[maxn][maxn];
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
        string s;
        cin>>s;
        int n=s.length(),ans=1;
        FOR(i,1,n) FOR(j,1,n) dp[i][j]=0;
        FOR(i,1,n) dp[i][i]=1;
        s="#"+s;
        FOR(i,1,n)
            FOD(j,i-1,1)
                if (s[i]==s[j])
                {
                    if (i-j<=1) dp[j][i]=1, ans=max(ans,2ll);
                    else
                    {
                        if (dp[j+1][i-1]) 
                        {
                            dp[j][i]=1;
                            ans=max(ans,i-j+1);
                        }
                    }
                }
        cout<<ans<<'\n';
    }    
}
