#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 105
int n,a[maxn];
int S[4],remain,ans=INF;
vector<vector<int>> dp;
void Try(int i)
{
    if (max({S[1],S[2],S[3]})-min({S[1],S[2],S[3]})-remain >= ans) return;
    FOR(j,1,3)
    {
        S[j]+=a[i];
        remain-=a[i];
        if (i==n)
            ans=min(ans,max({S[1],S[2],S[3]})-min({S[1],S[2],S[3]}));
        else Try(i+1);
        S[j]-=a[i];
        remain+=a[i];
    }
}
void sub1()
{
    Try(1);
    cout<<ans;
}
void sub2()
{
    dp.resize(remain+1,vector<int>(remain+1));
    dp[0][0]=1;
    FOR(i,1,n) 
        FOD(j,remain,0)
            FOD(k,remain,0)
                if (dp[i][k])
                {
                    dp[j+a[i]][k]=1;
                    dp[j][k+a[i]]=1;
                }
    FOR(i,0,remain)
        FOR(j,0,remain)
            if (dp[i][j]) ans=min(ans,max({i,j,remain-i-j})-min({i,j,remain-i-j}));
    cout<<ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i], remain+=a[i];
    // if (n<=20) sub1();
    // else 
    sub2();
}
