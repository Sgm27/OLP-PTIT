#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 1005
int n,a[maxn],dp[maxn];
struct Fenwick{
    int t[maxn];
    void reset()
    {
        memset(t,0,sizeof(t));
    }
    void update(int x,int val)
    {
        for (;x<=maxn-5;x+=x&-x) t[x]=max(t[x],val);
    }
    int get(int x)
    {
        int ans=0;
        for (;x>0;x-=x&-x) ans=max(ans,t[x]);
        return ans;
    }
} fw;

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
        cin>>n;
        FOR(i,1,n) cin>>a[i];
        fw.reset();
        int ans=0;
        FOR(i,1,n)
        {
            dp[i]=fw.get(a[i]-1)+a[i];
            fw.update(a[i],dp[i]);
            ans=max(ans,dp[i]);
        } 	
        cout<<ans<<"\n";
    }
}
