#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
const int N=1e6;
#define maxn 
vector<int> prime;
vector<pii> p;
int IsNotprime[N+5],n,k;
void eratos()
{
    IsNotprime[0]=IsNotprime[1]=1;
    FOR(i,1,sqrt(N))
        if (!IsNotprime[i])
            for (int j=i*i;j<=N;j+=i) IsNotprime[j]=1;
    FOR(i,1,N)
        if (!IsNotprime[i]) prime.push_back(i);
}
void ptich(int n)
{
    int idx=0;
    while (n!=1 && prime[idx]<=sqrt(n))
    {
        int cnt=0;
        while (n%prime[idx]==0) cnt++, n/=prime[idx];
        if (cnt) p.push_back({prime[idx],cnt});
        idx++;
    }
    if (n!=1) p.push_back({n,1});
}
int deg(int n,int k)
{
    int ans=0;
    for (int i=k;i<=n;i*=k) ans+=n/i;
    return ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    eratos();
    int tc; cin>>tc;
    while (tc--)
    {
        int ans=1e18;
        cin>>n>>k;
        ptich(k);
        for (pii x : p)
        {
            int d=deg(n,x.first);
            ans=min(ans,d/x.second);
        }
        cout<<ans<<"\n";
        p.clear();
    }
    cerr<<TIME;
}
