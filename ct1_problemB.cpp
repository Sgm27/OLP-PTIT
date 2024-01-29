#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 151
int n,t;
vector<vector<int>> dp;
struct data{
    int val,cnt2,cnt5;
} a[maxn];
void ptich(data &x)
{
    while (x.val%2==0) x.cnt2++, x.val/=2;
    while (x.val%5==0) x.cnt5++, x.val/=5; 
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>t;
    FOR(i,1,n) cin>>a[i].val, ptich(a[i]);
    int max_cnt2=0,max_cnt5=0;
    FOR(i,1,n) max_cnt2+=a[i].cnt2, max_cnt5+=a[i].cnt5;
    dp.resize(max_cnt2+5,vector<int>(max_cnt5+2));
    FOR(i,1,n)
        FOD(j,max_cnt2,a[i].cnt2)
            FOD(k,max_cnt5,a[i].cnt5)
            {
                if (j-a[i].cnt2==0 && k-a[i].cnt5==0) 
                {
                    dp[j][k]=1;
                    continue;
                }
                if (dp[j-a[i].cnt2][k-a[i].cnt5]) 
                {
                    if (!dp[j][k]) dp[j][k]=dp[j-a[i].cnt2][k-a[i].cnt5]+1;
                    else dp[j][k]=min(dp[j][k],dp[j-a[i].cnt2][k-a[i].cnt5]+1);
                }
            }
    int ans=0;
    FOR(i,1,max_cnt2)
        FOR(j,1,max_cnt5)
            if (dp[i][j] && dp[i][j]<=t) ans=max(ans,min(i,j));
    cout<<ans;
}