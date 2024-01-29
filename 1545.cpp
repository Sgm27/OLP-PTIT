#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 100005
int n,q,a[maxn],st[25][maxn],lz[maxn];
int get_min(int l,int r)
{
    int k=log2(r-l+1);
    return max(st[k][l],st[k][r-(1<<k)+1]);
}
void make_RMQ()
{
    FOR(i,1,n) st[0][i]=a[i];
    FOR(i,1,log2(n))
    {
        FOR(j,1,n-(1<<i)+1)
            st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,q)
    {
        int u,v,k;
        cin>>u>>v>>k;
        lz[u]+=k;
        lz[v+1]-=k;
    }
    int add=0;
    FOR(i,1,n)
    {
        add+=lz[i];
        a[i]=add;
    }
    make_RMQ();
    cin>>q;
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<get_min(l,r)<<"\n";
    }
}
