#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,a[maxn];
int m1[maxn],m2[maxn];
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
        FOR(i,1,n) cin>>a[i], m1[i]=0, m2[i]=0;
        int Max=a[1], Min=a[n];
        FOR(i,1,n) 
            if (a[i]>=Max) m1[i]=1, Max=a[i];
        FOD(i,n,1)
            if (a[i]<Min) m2[i]=1, Min=a[i];
        m2[n]=1;
        int cnt=0;
        FOR(i,1,n)
            if (m1[i] && m2[i]) 
            {
                // cout<<i<<" ";
                cnt++;
            }
        // cout<<"\n";
        cout<<cnt<<"\n";
    }
}
