#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,a[maxn],f1[maxn],f2[maxn];
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
        FOR(i,1,n) cin>>a[i], f1[i]=1, f2[i]=1;
        f1[0]=f2[n+1]=0;
        FOR(i,1,n) 
            if (a[i]>a[i-1]) f1[i]=f1[i-1]+1;
            else f1[i]=1;
        FOD(i,n,1)
            if (a[i]>a[i+1]) f2[i]=f2[i+1]+1;
            else f2[i]=1;
        int ans=0;
        FOR(i,1,n)
        {
            ans=max(ans,f1[i]+f2[i]-1);
        }
        cout<<ans<<"\n";
    }
}