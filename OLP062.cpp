#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,q,a[maxn];
struct Segment_Tree{
    int st[maxn*4],lz[maxn*4];
    void build(int id,int l,int r)
    {
        if (l==r) return st[id]=a[l], void();
        int m=(l+r)/2;
        build(id*2,l,m);
        build(id*2+1,m+1,r);
        st[id]=max(st[id*2],st[id*2+1]);
    }
    void Push(int id)
    {
        st[id*2]+=lz[id];
        (st[id*2+1]+=lz[id]);
        (lz[id*2]+=lz[id]);
        (lz[id*2+1]+=lz[id]);
        lz[id]=0;
    }
    void update(int id,int l,int r,int u,int v,int val)
    {
        if (r<u || l>v) return;
        if (l>=u && r<=v) 
        {
            (st[id]+=val);
            (lz[id]+=val);
            return;
        }
        int m=(l+r)/2;
        if (lz[id]) Push(id);
        update(id*2,l,m,u,v,val);
        update(id*2+1,m+1,r,u,v,val);
        st[id]=max(st[id*2],st[id*2+1]);
    }
    int get(int id,int l,int r,int u,int v)
    {
        if (r<u || l>v) return 0;
        if (l>=u && r<=v) return st[id];
        int m=(l+r)/2;
        if (lz[id]) Push(id);
        int t1=get(id*2,l,m,u,v);
        int t2=get(id*2+1,m+1,r,u,v);
        return max(t1,t2);
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
    FOR(i,1,n) cin>>a[i];
    ST.build(1,1,n);
    while (q--)
    {
        int type,u,v,val;
        cin>>type>>u>>v;
        if (type==1)
        {
            cout<<ST.get(1,1,n,u,v)<<"\n";
        }
        else
        {
            cin>>val;
            ST.update(1,1,n,u,v,val);
        }
    }
}
