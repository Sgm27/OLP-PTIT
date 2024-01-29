#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define ld float
#define bit(i,n) ((n>>i)&1)
#define pii pair<int,int>
#define maxn 25
int n;
ld cost[maxn][maxn],dp[1<<21];
struct point{
    int x,y;
} p[maxn];
ld distance(point a,point b)
{
    return (ld)sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int find_bit(int mask)
{
    for (int i=0;i<n;i++)
        if (bit(i,mask)==0) return i;
}
void process()
{
    for (int i=0;i<(1<<n);i++) dp[i]=1e9;
    dp[0]=0;
    for (int mask=0;mask<(1<<n);mask++)
    {
        int k=find_bit(mask);
        for (int i=0;i<n;i++)
            if (bit(i,mask)==0 && i!=k)
            {
                int next_mask=mask+(1<<i)+(1<<k);
                dp[next_mask]=min(dp[next_mask],dp[mask]+distance(p[i],p[k]));
            }
    }
    ld ans=dp[(1<<n)-1];
    cout<<fixed<<setprecision(2)<<ans<<"\n";
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
        cin>>n;
        n*=2;
        for (int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
        process();
    }
}
