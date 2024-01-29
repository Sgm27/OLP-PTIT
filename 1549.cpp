#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 100005
int n,q,t[maxn],res[maxn];
pii a[maxn];
struct query{
    int l,r,k,id;
} Q[maxn];
void update(int x)
{
    for (;x<=n;x+=(x&-x)) t[x]++;
}
int get(int x)
{
    int ans=0;
    for (;x>0;x-=(x&-x)) ans+=t[x];
    return ans;
}
bool cmp(query a,query b)
{
    return a.k>b.k;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n)
    {
        cin>>a[i].first;
        a[i].second=i;
    } 
    sort(a+1,a+1+n);
    cin>>q;
    FOR(i,1,q) cin>>Q[i].l>>Q[i].r>>Q[i].k, Q[i].id=i;
    sort(Q+1,Q+1+q,cmp);
    int idx=1,i=n;
    while (1)
    {
        while (i>=1 && a[i].first>Q[idx].k) 
        {
            update(a[i].second);
            i--;
        }
        res[Q[idx].id]=get(Q[idx].r)-get(Q[idx].l-1);
        if (idx<q) idx++; else break;
    }
    FOR(i,1,q) cout<<res[i]<<"\n";
}
