#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
const int MOD=1e9+7,N=1000;
#define maxn 200005
int n,a[maxn],Cprime[N+5];
int pos[N+5];
vector<int> prime;
void init()
{
    FOR(i,1,N) Cprime[i]=i;
    FOR(i,2,sqrt(N))
        if (Cprime[i]==i) 
            for (int j=i*i;j<=N;j+=i) Cprime[j]=i;
    int idx=-1;
    FOR(i,2,N)
        if (Cprime[i] == i) 
        {
            pos[i]=++idx;
            prime.push_back(i);
        }
}
vector<vector<int>> have,lz;
int calc(int x,int idx)
{
    if (x <= N)
    {
        while (x != 1)
        {
            int tmp=Cprime[x];
            while (x%tmp==0) 
            {
                x/=tmp;
                lz[idx][pos[tmp]]++;
            }
        }
    }
    else
    {
        for (int k : prime)
        {
            if (k > x) break;
            if (x % k==0)
                while (x % k==0) 
                {
                    x/=k;
                    lz[idx][pos[k]]++;
                }
        }
    }
    return x;
}
struct Segment_Tree{
    vector<unordered_map<int,int>> st;
    Segment_Tree(int sz)
    {
        st.resize(sz*4+1);
    }
    void update(int id,int l,int r,int p,int val)
    {
        if (r<p || l>p) return;
        if (l == r) 
        {
            st[id].insert({val,1});
            return;
        }
        int m=(l+r)/2;
        update(id*2,l,m,p,val);
        update(id*2+1,m+1,r,p,val);
        st[id]=st[id*2];
        for (auto it : st[id*2+1])
            st[id][it.first] += it.second;
    }
    unordered_map<int,int> get(int id,int l,int r,int u,int v)
    {
        if (r<u || l>v) return {};
        if (l>=u && r<=v) return st[id];
        int m=(l+r)/2;
        unordered_map<int,int> t1=get(id*2,l,m,u,v);
        unordered_map<int,int> t2=get(id*2+1,m+1,r,u,v);
        unordered_map<int,int> ans=t1;
        for (auto it : t2)
            ans[it.first] += it.second;
        return ans;
    }
};
int Pow(int a, int n)
{
    if (!n) return 1;
    if (n==1) return a;
    int tmp=Pow(a,n/2)%MOD;
    tmp=1ll*tmp*tmp%MOD;
    if (n%2) tmp=1ll*tmp*a%MOD;
    return tmp;
}
void pre_process()
{
    for (int j=0;j<168;j++)
    {
        int add=0;
        for (int i=1;i<=n;i++)
        {
            add += lz[i][j];
            have[i][j] += add;
        }
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    cin>>n;
    Segment_Tree ST(n);
    have.resize(n+1,vector<int>(169,0));
    lz.resize(n+1,vector<int>(169,0));
    FOR(i,1,n) 
    {
        int x; cin>>x;
        int val=calc(x,i);
        if (val != 1) ST.update(1,1,n,i,val);
    }
    pre_process();
    int q; cin>>q;
    while (q--)
    {
        int u,v; cin>>u>>v;
        int answer=1;
        for (int i=0;i<168;i++)
        {
            int Count=have[v][i]-have[u-1][i];
            if (!Count) continue; 
            answer=1ll*(1ll*answer*Pow(prime[i],Count-1)%MOD)*(prime[i]-1)%MOD;
        }
        unordered_map<int,int> tmp=ST.get(1,1,n,u,v);
        for (auto it : tmp)
        {
            cout<<it.first<<" "<<it.second<<"\n";
            answer=1ll*(1ll*answer*Pow(it.first,it.second-1)%MOD)*(it.first-1)%MOD;
        }
        cout<<answer<<"\n";
    }
}
