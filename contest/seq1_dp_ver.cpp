#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n+1),f(n+1,0);
    FOR(i,1,n) cin>>a[i], f[i]=max(f[i-1]+a[i],a[i]);
    cout<<*max_element(f.begin()+1,f.end());
}
