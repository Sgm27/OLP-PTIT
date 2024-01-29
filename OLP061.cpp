#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
string s;
int n,q,p[maxn];
struct node{
    int hash,rhash,len;
} t[maxn*4];
node combine(node l,node r)
{
    node ans;
    ans.len=l.len+r.len;
    ans.hash=(l.hash*p[r.len]+r.hash)%MOD;
    ans.rhash=(r.rhash*p[l.len]+l.rhash)%MOD;
    return ans;
}
void build(int id,int l,int r)
{
    if (l==r) return t[id]={s[l]-'0',s[l]-'0',1}, void();
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=combine(t[id*2],t[id*2+1]);
}
void update(int id,int l,int r,int p,int val)
{
    if (r<p || l>p) return;
    if (l==r)
    {
        t[id]={val,val,1};
        return;
    }
    int m=(l+r)/2;
    update(id*2,l,m,p,val);
    update(id*2+1,m+1,r,p,val);
    t[id]=combine(t[id*2],t[id*2+1]);
}
node get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return {0,0,0};
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    node t1=get(id*2,l,m,u,v);
    node t2=get(id*2+1,m+1,r,u,v);
    return combine(t1,t2);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    n=s.length();
    s=" "+s;
    p[0]=1;
    FOR(i,1,n) p[i]=(p[i-1]*17)%MOD;
    build(1,1,n);
    cin>>q;
    while (q--)
    {
        string type; cin>>type;
        if (type=="c") 
        {
            int p,val;
            cin>>p>>val;
            update(1,1,n,p,val);
        }
        else
        {
            int u,v;
            cin>>u>>v;
            node ans=get(1,1,n,u,v);
            if (ans.hash==ans.rhash) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
