#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 15
int n,k,a[maxn];
vector<int> cong,tru;
int lcm(int a,int b)
{
    return a/__gcd(a,b)*b;
}
int f(int x)
{
    int ans=0;
    for (int t : cong) ans+=x/t;
    for (int t : tru) ans-=x/t;
    return ans;
}
void process()
{
    cong.clear(), tru.clear();
    for (int mask=1;mask<(1<<n);mask++)
    {
        int num_bit=0,cur=1;
        for (int i=0;i<n;i++)
            if ((mask>>i)&1)
            {
                num_bit++;
                cur=lcm(cur,a[i]);
            }
        if (num_bit & 1) cong.push_back(cur);
        else tru.push_back(cur);
    }
    // cout<<f(6)<<"\n";
    int l=0,r=1e18;
    while (r-l>1)
    {
        int m=(l+r)>>1;
        if (m-f(m)>=k) r=m;
        else l=m;
    }
    cout<<r<<"\n";
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
        cin>>n>>k;
        FOR(i,0,n-1) cin>>a[i];
        process();
    }
}
