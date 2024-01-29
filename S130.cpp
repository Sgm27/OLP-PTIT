#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,a[maxn];
struct Fenwick{
    vector<int> t;
    void init(int n)
    {
        t.resize(n+1);
    }
    void update(int x)
    {
        for(;x<=n;x+=x&-x) t[x]++;
    }
    int get(int x)
    {
        int ans=0;
        for(;x>0;x-=x&-x) ans+=t[x];
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
    cin>>n;
    int nmax=0;
    FOR(i,1,n) cin>>a[i], nmax=max(nmax,a[i]);
    fw.init(nmax);
    vector<int> v;
    int ans=0;
    FOD(i,n,1)
    {
        if (a[i]%2) 
        {
            for (int x : v) fw.update(x);
            v.clear();
            v.resize(0);
        }
        else
        {
            ans+=fw.get(a[i]);
            v.push_back(a[i]);
        }
    }
    cout<<ans;
}
