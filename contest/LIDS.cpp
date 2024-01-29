#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 1000006
int b[maxn],a[maxn];
int get(int n,int a[])
{
    int ans=0;
    fill(b+1,b+1+n,1e18);
    b[1]=0;
    for (int i=1;i<=n;i++)
    {
        int k=lower_bound(b+1,b+1+n,a[i])-b;
        b[k]=a[i];
        ans=max(ans,k-1);
    }
    return ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    int t1=get(n,a);
    reverse(a+1,a+1+n);
    cout<<n-max(t1,get(n,a));
}
