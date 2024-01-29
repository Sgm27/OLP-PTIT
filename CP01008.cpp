#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 1005
int n,a[maxn],p;
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
        cin>>n>>p;
        FOR(i,1,n) cin>>a[i];
        FOR(i,p+1,n) cout<<a[i]<<" ";
        FOR(i,1,p) cout<<a[i]<<" ";
        cout<<"\n"; 
    }
}
