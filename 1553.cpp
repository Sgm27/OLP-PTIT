#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 100005
int n,a[maxn],q;
vector<int> t[maxn*4];
void build(int id,int l,int r)
{
    if (l==r)
        return t[id].push_back(a[l]), void();
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    merge(t[id*2].begin(),t[id*2].end(),t[id*2+1].begin(),t[id*2+1].end(),back_inserter(t[id]));
}
int get(int id,int l,int r,int u,int v,int val)
{
    if (r<u || l>v) return 0;
    if (l>=u && r<=v) 
        return upper_bound(t[id].begin(),t[id].end(),val)-t[id].begin();
    int m=(l+r)/2;
    int t1=get(id*2,l,m,u,v,val);
    int t2=get(id*2+1,m+1,r,u,v,val);
    return t1+t2;
}
bool f(int x,int u,int v,int k)
{
    return get(1,1,n,u,v,x)>=k;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,n) cin>>a[i];
    build(1,1,n);
    while (q--)
    {
        int L=t[1][0]-1,R=t[1].back();
        int u,v,k;
        cin>>u>>v>>k;
        while (R-L>1)
        {
            int m=(L+R)/2;
            if (f(m,u,v,k)) R=m;
            else L=m;
        }
        cout<<R<<"\n";
    }
}
