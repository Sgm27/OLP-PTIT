#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=998244353,INF=9e18;
#define maxn 100005
int n,q;
string s;
struct node{
    int sum,answer;
    int pre[3],suf[3];
    node()
    {
        sum=answer=0;
        memset(pre,0,sizeof(pre));
        memset(suf,0,sizeof(suf));
    }
};
node t[maxn*4];
int Match0(int x)
{
    if (x==0) return 0;
    if (x==1) return 2;
    return 1;
}
int Match1(int x)
{
    if (x==0) return 1;
    if (x==1) return 0;
    return 2;
}
int Match2(int x)
{
    if (x==0) return 2;
    if (x==1) return 1;
    return 0;
}
node Merge(node l,node r)
{
    node ans;
    ans.sum=(l.sum+r.sum)%3;
    ans.pre[0]=l.pre[0]+r.pre[Match0(l.sum)];
    ans.pre[1]=l.pre[1]+r.pre[Match1(l.sum)];
    ans.pre[2]=l.pre[2]+r.pre[Match2(l.sum)];
    ans.suf[0]=r.suf[0]+l.suf[Match0(r.sum)];
    ans.suf[1]=r.suf[1]+l.suf[Match1(r.sum)];
    ans.suf[2]=r.suf[2]+l.suf[Match2(r.sum)];
    ans.answer=l.answer+r.answer+l.suf[0]*r.pre[0]+l.suf[1]*r.pre[2]+l.suf[2]*r.pre[1];
    return ans;
}
void update(int id,int l,int r,int p,int val)
{
    if (l>p || r<p) return;
    if (l==r)
    {
        node ans;
        ans.sum=val%3;
        ans.answer=(ans.sum==0);
        ans.pre[ans.sum]=1;
        ans.suf[ans.sum]=1;
        t[id]=ans;
        return;
    }
    int m= l+r >> 1;
    update(id << 1 ,l,m,p,val);
    update(id << 1 | 1,m+1,r,p,val);
    t[id]=Merge(t[id*2],t[id*2+1]);
}
node get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return node();
    if (l>=u && r<=v) return t[id];
    int m=l+r >> 1;
    node L=get(id << 1 ,l,m,u,v);
    node R=get(id << 1 | 1,m+1,r,u,v);
    return Merge(L,R);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    cin>>s; s=" "+s;
    FOR(i,1,n) update(1,1,n,i,s[i]-'0');
    while (q--)
    {
        int type,u,v;
        cin>>type>>u>>v;
        if (type==1)
            update(1,1,n,u,v);
        else
            cout<<get(1,1,n,u,v).answer<<"\n";
    }
}
