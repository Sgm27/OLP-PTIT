#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 303
int n,m,a[maxn][maxn],h[maxn][maxn];
int calc(int x,int y)
{
    int ans=0;
    FOR(i,1,3)
    {
        FOR(j,1,3) ans+=h[i][j]*a[x-2+i][y-2+j];
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
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>m;
        FOR(i,1,n)
            FOR(j,1,m) cin>>a[i][j];
        FOR(i,1,3)
            FOR(j,1,3) cin>>h[i][j];
        int sum=0;
        FOR(i,2,n-1)
        {
            FOR(j,2,m-1)
                sum+=calc(i,j);
        }
        cout<<sum<<"\n";
    }
}
