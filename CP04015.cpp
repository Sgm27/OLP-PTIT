#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 1005
int n,a[maxn],b[maxn];

int calc(int x)
{
    int s=0;
    FOR(i,1,n)
    {
        b[i]=a[i]/(x+1)+1;
        s+=b[i];
    }
    FOR(i,1,n)
        if (a[i]/b[i]!=a[1]/b[1]) return INF;
    return s;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    int Min=INF;
    FOR(i,1,n) cin>>a[i], Min=min(Min,a[i]);
    int ans=INF,cs;
    FOR(i,0,Min)
    {
        ans=min(ans,calc(i));
    }
    cout<<ans;
}
