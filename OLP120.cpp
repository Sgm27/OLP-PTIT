#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,q;
struct Segment_Tree{
    int st[maxn*4];
    void update(int id,int l,int r,int p,int val)
    {
        if (r<p || l>p) return;
        if (l==r) 
        {
            st[id]+=val;
            return;
        }
        int m=(l+r)/2;
        update(id*2,l,m,p,val);
        update(id*2+1,m+1,r,p,val);
        st[id]=min(st[id*2],st[id*2+1]);
    }
    int get(int id,int l,int r,int u,int v)
    {
        if (r<u || l>v) return INF;
        if (l>=u && r<=v) return st[id];
        int m=(l+r)/2;
        int t1=get(id*2,l,m,u,v);
        int t2=get(id*2+1,m+1,r,u,v);
        return min(t1,t2);
    }
} ST;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    while (q--)
    {
        int type,u,v;
        cin>>type>>u>>v;
        if (type==1)
            ST.update(1,1,n,u,v);
        else
        {
            if (v>=u)
                cout<<ST.get(1,1,n,u,v)<<"\n";
            else
                cout<<min(ST.get(1,1,n,u,n),ST.get(1,1,n,1,v))<<"\n";
        }
    }
}
