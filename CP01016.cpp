#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 1005
int n,a[maxn];
int lcm(int a,int b)
{
    return a/__gcd(a,b)*b;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n;
        FOR(i,1,n) cin>>a[i];
        a[0]=1, a[n+1]=1;
        FOR(i,1,n+1) cout<<lcm(a[i],a[i-1])<<" ";
        cout<<"\n";
    }
}
