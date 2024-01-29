#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18,N=150;
#define maxn 50005
int prime[N+5],n,q,pos[N+5];
vector<int> nt(40);
void init()
{
    FOR(i,1,N) prime[i]=i;
    FOR(i,2,sqrt(N))
        if (prime[i]==i) 
            for (int j=i*i;j<=N;j+=i) prime[j]=i;
    int idx=0;
    FOR(i,2,N)
        if (prime[i] == i) 
        {
            pos[i]=++idx;
            nt[idx]=i;
        }
}
vector<pii> ptich(int x)
{
    vector<pii> ans;
    while (x != 1)
    {
        int cnt=0,tmp=prime[x];
        while (x%tmp==0)
        {
            x/=tmp;
            cnt++;
        }
        ans.push_back({pos[tmp],cnt});
    }
    if (x!=1) ans.push_back({pos[x],1});
    return ans;
}
struct Segment_Tree{
    vector<int> st,lz;
    void init(int n)
    {
        st.resize(n << 2);
        lz.resize(n << 2);
    }
    void Push(int id,int l,int r,int m)
    {
        if (!lz[id]) return;
        st[id << 1]+=(m-l+1)*lz[id];
        st[id << 1 | 1]+=(r-m)*lz[id];
        lz[id << 1]+=lz[id];
        lz[id << 1 | 1]+=lz[id];
        lz[id]=0;
    }
    void update(int id,int l,int r,int u,int v,int val)
    {
        if (r<u || l>v) return;
        if (l>=u && r<=v) 
        {
            st[id]+=val*(r-l+1);
            lz[id]+=val;
            return;
        }
        int m=l+r >> 1;
        Push(id,l,r,m);
        update(id << 1,l,m,u,v,val);
        update(id << 1 | 1,m+1,r,u,v,val);
        st[id]=st[id << 1]+st[id << 1 | 1];
    }
    int get(int id,int l,int r,int u,int v)
    {
        if (r<u || l>v) return 0;
        if (l>=u && r<=v) return st[id];
        int m=l+r >> 1;
        Push(id,l,r,m);
        int t1=get(id << 1,l,m,u,v);
        int t2=get(id << 1 | 1,m+1,r,u,v);
        return t1+t2;
    }
};
int Pow(int a, int n,int p)
{
    if (!n || a==1) return 1;
    if (n==1) return a;
    int tmp=Pow(a,n >> 1,p)%p;
    tmp=1ll*tmp*tmp%p;
    if (n & 1) tmp=1ll*tmp*a%p;
    return tmp;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        Segment_Tree ST[37];
        cin>>n>>q;
        FOR(i,1,36) ST[i].init(n);
        while (q--)
        {
            int type,u,v;
            cin>>type>>u>>v;
            if (type==0)
            {
                int p,ans=1; cin>>p;
                if (u<=v)
                {
                    FOR(i,1,36)
                    {
                        int t=ST[i].get(1,1,n,u,v);
                        ans=(ans*Pow(nt[i],t,p))%p;
                    }
                }
                else
                {
                    FOR(i,1,36)
                    {
                        int t=ST[i].get(1,1,n,u,n)+ST[i].get(1,1,n,1,v);
                        ans=(ans*Pow(nt[i],t,p))%p;
                    }
                }
                cout<<ans<<"\n";
            }
            else
            if (type==1)
            {
                int val; cin>>val;
                vector<pii> vt=ptich(val);
                if (u<=v)
                {
                    for (pii it : vt)
                    {
                        ST[it.first].update(1,1,n,u,v,it.second);
                    }
                }
                else
                {
                    for (pii it : vt)
                    {
                        ST[it.first].update(1,1,n,u,n,it.second);
                        ST[it.first].update(1,1,n,1,v,it.second);
                    }
                }
            }
            else
            {
                int val; cin>>val;
                vector<pii> vt=ptich(val);
                if (u<=v)
                {
                    for (pii it : vt)
                    {
                        ST[it.first].update(1,1,n,u,v,-it.second);
                    }
                }
                else
                {
                    for (pii it : vt)
                    {
                        ST[it.first].update(1,1,n,u,n,-it.second);
                        ST[it.first].update(1,1,n,1,v,-it.second);
                    }
                }
            }
        }
    }
}
