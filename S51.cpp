#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,a[maxn],ps[maxn];
vector<int> ds;
bool f(int x)
{
    int sum=0,pre_pos=0;
    while (1)
    {
        if (pre_pos==n) return true;
        auto pos=lower_bound(ps+pre_pos+1,ps+n+1,sum+ps[x]);
        if (pos==ps+n+1 || *pos!=sum+ps[x]) return false;
        else
        {
            pre_pos=pos-ps;
            sum+=ps[x];
        }
    }
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
        ds.clear();
        cin>>n;
        FOR(i,1,n) cin>>a[i], ps[i]=ps[i-1]+a[i];
        int ans=INF;
        FOR(i,1,n)
            if (ps[n]%ps[i]==0) ds.push_back(i);
        for (int x : ds)
            if (f(x)) 
            {
                cout<<ps[x]<<"\n";
                break;
            }
    }
}
