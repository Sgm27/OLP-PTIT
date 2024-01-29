#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18,base=10;
#define maxn 100005
int p[maxn],h[10][maxn],n,q;
int lz[maxn*4];
string s;
struct node{
    int hash,len;
} t[maxn*4];
node Merge(node l,node r)
{
    node ans;
    ans.hash=(l.hash*p[r.len]+r.hash)%MOD;
    ans.len=l.len+r.len;
    return ans;
}
void build(int id,int l,int r)
{
    if (l==r) return t[id]={s[l]-'0',1}, void();
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=Merge(t[id*2],t[id*2+1]);
}
void Push(int id,int l,int r,int m)
{
    if (lz[id] == -1) return;
    int val=lz[id];
    t[id*2]={h[val][m-l+1],m-l+1};
    t[id*2+1]={h[val][r-m],r-m};
    lz[id*2]=lz[id*2+1]=val;
    lz[id]=-1;
}
void update(int id,int l,int r,int u,int v,int val)
{
    if (r<u || l>v) return;
    if (l>=u && r<=v)
    {
        t[id]={h[val][r-l+1],r-l+1};
        lz[id]=val;
        return;
    }
    int m=(l+r)/2;
    Push(id,l,r,m);
    update(id*2,l,m,u,v,val);
    update(id*2+1,m+1,r,u,v,val);
    t[id]=Merge(t[id*2],t[id*2+1]);
}
node get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return {0,0};
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    Push(id,l,r,m);
    node t1=get(id*2,l,m,u,v);
    node t2=get(id*2+1,m+1,r,u,v);
    return Merge(t1,t2);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    memset(lz,-1,sizeof(lz));
    cin>>n>>q;
    cin>>s; s=" "+s;
    p[0]=1;
    FOR(i,1,n) p[i]=(p[i-1]*base)%MOD;
    FOR(i,0,9)
    {
        h[i][1]=i;
        FOR(j,2,n) h[i][j]=(h[i][j-1]*base+i)%MOD; 
    }
    build(1,1,n);
    while (q--)
    {
        int type,u,v;
        cin>>type>>u>>v;
        if (type==1)
        {
            int val; cin>>val;
            update(1,1,n,u,v,val);
        }
        else
        {
            int d; cin>>d;
            node L=get(1,1,n,u,v-d);
            node R=get(1,1,n,u+d,v);
            if (L.hash==R.hash) cout<<"YES\n"; else cout<<"NO\n";
        }
    }
}
