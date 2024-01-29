#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 200005 
struct query{
    int type,u,v,c,id;
    // A = 1
    // ? = 2
    // Q = 3
    // C = 4
} Q[maxn];
int n,q;
string ans[maxn];
vector<query> Quest[maxn];
struct DSU{
    int r[maxn],n;
    DSU(int sz)
    {
        n=sz;
        FOR(i,1,n) r[i]=i;
    }
    int get_root(int u)
    {
        if (u==r[u]) return u;
        return r[u]=get_root(r[u]);
    }
    void join(int u,int v)
    {
        u=get_root(u);
        v=get_root(v);
        if (u==v) return;
        return r[u]=v, void();
    }
};
void solve()
{
    DSU dsu(n);
    int commit=0;
    FOR(i,1,q)
    {
        if (Q[i].type==1) dsu.join(Q[i].u,Q[i].v);
        else 
        if (Q[i].type==2) 
        {
            if (dsu.get_root(Q[i].u) == dsu.get_root(Q[i].v)) 
                ans[Q[i].id]="Y";
            else 
                ans[Q[i].id]="N";
        }  
        else
        if (Q[i].type==4)
        {
            commit++;
            for (query x : Quest[commit]) 
            {
                if (dsu.get_root(x.u) == dsu.get_root(x.v)) 
                    ans[x.id]="Y";
                else 
                    ans[x.id]="N";
            }
        }
    }
    FOR(i,1,q)
        if (ans[i]!="#") cout<<ans[i];
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,n) ans[i]="#";
    FOR(i,1,q)
    {
        char t; cin>>t;
        if (t=='A')
        {
            int u,v;
            cin>>u>>v;
            Q[i].type=1;
            Q[i].u=u, Q[i].v=v, Q[i].id=i;
        }
        else 
        if (t=='?')
        {
            int u,v;
            cin>>u>>v;
            Q[i].type=2;
            Q[i].u=u, Q[i].v=v, Q[i].id=i;
        }
        else
        if (t=='Q')
        {
            int c,u,v;
            cin>>c>>u>>v;
            Quest[c].push_back({3,u,v,c,i});
            if (!c) ans[i]="N";
            Q[i].type=3;
            Q[i].u=u, Q[i].v=v, Q[i].id=i;
        }
        else 
        {
            Q[i].type=4;
            Q[i].id=i;
        }
    }
    solve();
}
