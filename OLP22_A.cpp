#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18,N=1e6;
#define maxn 
int prime[N+5];
void eratos()
{
    FOR(i,1,N) prime[i]=i;
    for (int i=2;i<=sqrt(N);i++)
        if (prime[i]==i)
            for (int j=i*i;j<=N;j+=i) prime[j]=i;
}
void add(map<int,int> &mp,int n)
{
    while (n!=1)
    {
        int i=prime[n],cnt=0;
        while (n%i==0)
        {
            n/=i;
            cnt++;
        }
        mp[i]+=cnt;
    }
}
void solve(int n)
{
    map<int,int> count;
    add(count,n), add(count,n+1), add(count,n+2);
    int p1=1,p2=1;
    for (pii x : count) 
    {
        p1*=(x.second+1);
        p2*=(x.second*2+1);
    }
    cout<<p2/2-p1+1<<"\n";
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
        int n; cin>>n;
        solve(n);
    }
}
