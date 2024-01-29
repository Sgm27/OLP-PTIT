#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=998244353,INF=9e18;
#define maxn 100005
int n,p[maxn],q;
string s;
struct node{
    int sign;  // sign of last
    int first,val,last;
    int len; // lenght of first
    node ()
    {
        sign=first=last=len=val=0;
    }
};
struct Segment_tree{
    vector<node> t;
    Segment_tree (int n)
    {
        t.resize(4*n);
    }
    node Merge(node l,node r)
    {
        node ans;
        if (!l.sign && !r.sign)
        {
            ans.len=l.len+r.len;
            ans.first=l.first*p[r.len]+r.first;
            ans.sign=ans.val=ans.last=0;
        }
        else
        if (!l.sign && r.sign)
        {
            ans.len=l.len+r.len;
            ans.val=r.val;
            ans.sign=r.sign;
            ans.first=l.first*p[r.len]+r.first;
            ans.last=r.last;
        }
        else
        if (l.sign && !r.sign)
        {
            ans.val=l.val;
            ans.len=l.len;
            ans.first=l.first;
            ans.last=l.last*p[r.len]+r.first*l.sign;
            ans.sign=l.sign;
        }
        else
        {
            int mid_val=l.last*p[r.len]+r.first*l.sign;
            ans.val=l.val+mid_val+r.val;
            ans.len=l.len;
            ans.first=l.first;
            ans.last=r.last;
            ans.sign=r.sign;
        }
        ans.first=(ans.first + MOD*MOD)%MOD;
        ans.last=(ans.last + MOD*MOD)%MOD;
        ans.val=(ans.val + MOD*MOD)%MOD;
        return ans;
    }
    void build(int id,int l,int r)
    {
        if (l==r) 
        {
            node ans=node();
            if (isdigit(s[l]))
            {
                ans.first=s[l]-'0';
                ans.len=1;
                t[id]=ans;
            }
            else
            {
                if (s[l]=='-')
                    ans.sign=-1;
                else 
                    ans.sign=1;
                t[id]=ans;
            }
            return;
        }
        int m=l+r >> 1;
        build(id << 1,l,m);
        build(id << 1 | 1,m+1,r);
        t[id]=Merge(t[id << 1],t[id << 1 | 1]);
    }
    void update(int id,int l,int r,int p,char val)
    {
        if (r<p || l>p) return;
        if (l==r)
        {
            node ans=node();
            if (isdigit(val))
            {
                ans.first=val-'0';
                ans.len=1;
                t[id]=ans;
            }
            else
            {
                if (val=='-')
                    ans.sign=-1;
                else
                    ans.sign=1;
                t[id]=ans;
            }
            return;
        }
        int m=l+r >> 1;
        update(id << 1,l,m,p,val);
        update(id << 1 | 1,m+1,r,p,val);
        t[id]=Merge(t[id << 1],t[id << 1 | 1]);
    }
    node get(int id,int l,int r,int u,int v)
    {
        if (r<u || l>v) return node();
        if (l>=u && r<=v) return t[id];
        int m=l+r >> 1;
        node Left=get(id << 1,l,m,u,v);
        node Right=get(id << 1 | 1,m+1,r,u,v);
        return Merge(Left,Right);
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    n=s.length(); s=" "+s;
    p[0]=1;
    FOR(i,1,n) p[i]=(p[i-1]*10)%MOD;
    Segment_tree ST(n);
    ST.build(1,1,n);
    cin>>q;
    while (q--)
    {
        char type; cin>>type;
        if (type=='?') 
        {
            int u,v; cin>>u>>v;
            node ans=ST.get(1,1,n,u,v);
            int result=(ans.first+ans.val+ans.last+MOD*MOD)%MOD;
            cout<<result<<"\n";
        }
        else
        if (type=='!')
        {
            int p; char val;
            cin>>p>>val;
            ST.update(1,1,n,p,val);
        }
    }
}
