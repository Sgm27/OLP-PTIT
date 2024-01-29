#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 1005
int n,a[maxn],b[maxn];
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
        FOR(i,1,n) cin>>b[i];
        int nim=(a[1]%(b[1]+1));
        FOR(i,2,n) nim^=(a[i]%(b[i]+1));
        if (nim) cout<<"First\n"; else cout<<"Second\n";
    }
}
