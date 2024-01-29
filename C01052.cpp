#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
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
    int tc; cin>>tc;
    while (tc--)
    {
        int n,ans=0;
        cin>>n;
        FOR(i,1,sqrt(n))	
            if (n%i==0)
            {
                if (i%2==0) ans++;
                if (i!=n/i && (n/i)%2==0) ans++; 
            }
        cout<<ans<<"\n";
    }
}
