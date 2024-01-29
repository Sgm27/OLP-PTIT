#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 100005
int n,a[maxn],d[maxn*10];
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
        memset(d,0,sizeof(d));
        cin>>n;
        FOR(i,1,n) cin>>a[i], d[a[i]]++;
        FOR(i,1,n)
            if (d[a[i]]%2) 
            {
                cout<<a[i]<<"\n";
                break;
            }
    }
}
