#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 505
int n,a[maxn],S1,S2;
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
        S1=S2=0;
        cin>>n;
        FOR(i,1,n) cin>>a[i];
        sort(a+1,a+1+n,greater<int>());
        FOR(i,1,n)
            if (S1<S2) S1+=a[i];
            else S2+=a[i];
        cout<<max(S1,S2)<<"\n"; 	
    }
}
