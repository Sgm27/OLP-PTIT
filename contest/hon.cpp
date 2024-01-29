#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 505 
int n,k,a[maxn][maxn],dp[maxn][maxn];
void process()
{
    int size=n;
    FOR(i,1,n)
    {
        
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    int size=n;
    FOR(i,1,n)
    {
        FOR(j,1,size) cin>>a[i][j];
        size++;
    }
    size--;
    FOR(i,n+1,2*n-1)
    {
        size--;
        FOR(j,1,size) cin>>a[i][j];
    }
    process();
}
