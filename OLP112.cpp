#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 1000005
#define maxbit 32
int n,a[maxn],prefix_xor,nnode,ans;
struct trie{
    int child[2],val;
} t[maxn*4];
void reset(int n)
{
    FOR(i,0,n)
    {
        t[i].child[0]=t[i].child[1]=0;
        t[i].val=0;
    }
}
void add(int k)
{
    int node=0;
    FOD(i,maxbit,0)
    {
        int id=(k>>i)&1;
        if (!t[node].child[id]) t[node].child[id]=++nnode;
        node=t[node].child[id];
    }
    t[node].val=k;
}
int find_max_xor(int k)
{
    int node=0;
    FOD(i,maxbit,0)
    {
        int id=(k>>i)&1;
        if (t[node].child[id^1]) node=t[node].child[id^1];
        else node=t[node].child[id];
    }
    return t[node].val^k;
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
        ans=prefix_xor=nnode=0;
        FOR(i,1,n) cin>>a[i];
        FOR(i,1,n)
        {
            prefix_xor^=a[i];
            ans=max(ans,find_max_xor(prefix_xor));
            add(prefix_xor);
        }
        cout<<ans<<"\n";
        reset(nnode+5);
    }
}