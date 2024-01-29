#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 201
int k,dp[maxn][maxn][maxn];
string s;
int calc(int l,int r,int k)
{
    if (l>r || k<=0) return 0;
    if (s[l]==')' || s[r]=='(') return 0; 
    if (l==r-1 && k!=1) return 0;
    if (dp[l][r][k] != -1) return dp[l][r][k];
    if (l==r-1)
    {
        if (k==1)
        {
            if (s[l]=='(' && s[r]==')') return 1;
            else
            if (s[l]=='?' && s[r]=='?') return 1;
            else
            if (s[l]=='?' && s[r]==')') return 1;
            else
            if (s[l]=='(' && s[r]=='?') return 1; 
        }
        else return 0;
    }
    int res=0;
    if (s[l]=='?' && s[r]=='?') res+=calc(l+1,r-1,k-1);
    else
    if (s[l]=='(' && s[r]==')') res+=calc(l+1,r-1,k-1);
    else
    if (s[l]=='?' && s[r]==')') res+=calc(l+1,r-1,k-1);
    else 
    if (s[l]=='(' && s[r]=='?') res+=calc(l+1,r-1,k-1);
    for (int kk=k;kk>=1;kk--)
    {
        for (int i=r-1;i>l;i--) 
        {
            res+=calc(l,i,kk)*calc(i+1,r,k);
            if (kk != k) res+=calc(l,i,k)*calc(i+1,r,kk);
        }
    }
    if (dp[l][r][k] == -1) dp[l][r][k]=res;
    return res;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    freopen("thu.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin>>k;
    cin>>s;
    cout<<calc(0,s.length()-1,k);
    cout<<"\n";
    for (int i=0;i<s.length()-1;i++)
        for (int j=i+1;j<s.length();j++)
            for (int kk=1;kk<=k;kk++)
                if (dp[i][j][kk] > 0) cout<<i<<" "<<j<<" "<<kk<<" "<<dp[i][j][kk]<<"\n";
    cout<<dp[5][6][1]<<"\n";
}
