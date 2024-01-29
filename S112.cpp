#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 
int a[20],dp[20][180],arr[15],l,r,nmax;
int thu(int i,bool gh,int sum)
{
    if (!i)
    {
        FOR(i,1,nmax) 
            if (sum%arr[i]==0) return 1;
        return 0;
    }
    if (gh==false && dp[i][sum]>=0) return dp[i][sum];
    int maxc=gh ? a[i] : 9,res=0;
    for (int c=0;c<=maxc;c++)
    {
        bool ghm=gh & c==maxc;
        res+=thu(i-1,ghm,sum+c);
    }
    if (gh==false) dp[i][sum]=res;
    return res;
}
int G(int x)
{
    int n=0;
    while (x)
    {
        a[++n]=x%10;
        x/=10;
    }
    return thu(n,true,0);
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
        memset(dp,-1,sizeof(dp));
        cin>>l>>r;
        cin>>nmax;
        FOR(i,1,nmax) cin>>arr[i];
        cout<<G(r)-G(l-1)<<"\n";
    }
}
