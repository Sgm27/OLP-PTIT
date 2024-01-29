#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 100005
int n,a[maxn],q,t[maxn*4],lazy[maxn*4];
void Push(int id)
{
    t[id*2]+=lazy[id];
    t[id*2+1]+=lazy[id];
    lazy[id*2]+=lazy[id];
    lazy[id*2+1]+=lazy[id];
    lazy[id]=0;
}
void update(int id,int l,int r,int u,int v,int val)
{
    if (r<u || l>v) return;
    if (l>=u && r<=v) 
    {
        t[id]+=val;
        lazy[id]+=val;
        return;
    }
    if (lazy[id]) Push(id);
    int m=(l+r)/2;
    update(id*2,l,m,u,v,val);
    update(id*2+1,m+1,r,u,v,val);
    t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return LLONG_MIN;
    if (l>=u && r<=v) return t[id];
    if (lazy[id]) Push(id);
    int m=(l+r)/2;
    int t1=get(id*2,l,m,u,v);
    int t2=get(id*2+1,m+1,r,u,v);
    return max(t1,t2);
}
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
        int type; cin>>type;
        if (type==1)
        {
            int u,v,k;
            cin>>u>>v>>k;
            update(1,1,n,u,v,k);
        }
        else
        {
            int u,v;
            cin>>u>>v;
            cout<<get(1,1,n,u,v)<<"\n";
        }
    }
}
