#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,a[maxn],q;
struct Fenwick{
    vector<int> t;
    Fenwick(int n)
    {
        t.resize(n+1);
    }
    void up_point(int x,int val)
    {
        for (;x<=n;x+=x&-x) t[x]+=val;
    }
    void up_range(int l,int r,int val)
    {
        up_point(l,val);
        up_point(r+1,-val);
    }
    int get_val(int x)
    {
        int ans=0;
        for (;x>0;x-=x&-x) ans+=t[x];
        return ans;
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    Fenwick fw(n);
    FOR(i,1,n) cin>>a[i], fw.up_point(i,a[i]-a[i-1]);
    cin>>q;
    while (q--)
    {
        int type,l,r,v;
        cin>>type;
        if (type==1)
        {
            cin>>l>>r>>v;
            fw.up_range(l,r,v);
        }
        else
        {
            int p;
            cin>>p;
            cout<<fw.get_val(p)<<"\n";
        }
    }
}
