#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 20
int n,a[maxn],x[maxn],ans;
void update()
{
    int sum[4]={};
    FOR(i,1,n)
        sum[x[i]]+=a[i];
    FOR(i,1,3) 
        if (sum[i]!=sum[1]) return;
    ans+=1;
}
void Try(int i)
{
    FOR(j,1,3)
    {
        x[i]=j;
        if (i==n)
            update();
        else Try(i+1);
    }
}
void process()
{
    Try(1);
    cout<<ans<<"\n";
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
        ans=0;
        cin>>n;
        FOR(i,1,n) cin>>a[i];
        process();
    }
}
