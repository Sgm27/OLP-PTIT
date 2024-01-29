#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
// #define int long long
#define pii pair<int,int>
#define maxn 100005
int n,m;
vector<int> prefix;
void init()
{
    int faci=1;
    FOR(i,1,m)
    {
        faci=(1ll*faci*i)%m;
        prefix[i]=(prefix[i-1]+1ll*i*faci)%m;
    }
}
int sum(int x)
{
    return (1ll*x*(x+1)/2)%m;
}
int F(long long x)
{
    long long ans=0;
    (ans+=prefix[min(1ll*m,x)])%=m;
    if (x>=m)
    {
        ans=ans+((1ll*x/m*sum(m)+sum(x%m))%m)*(x%m);
        ans%=m;
    }
    else
    {
        ans=ans+(1ll*sum(x)*(x%m))%m;
        ans%=m;
    }
    return ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    prefix.resize(m+1);
    init();
    int res=0;
    FOR(i,1,n)
    {
        long long x; cin>>x;
        (res+=F(x))%=m;
    }
    cout<<res;
}