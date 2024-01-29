#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 1005
int n,a[maxn];

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
        sort(a+1,a+1+n);
        int ans=0;
        FOR(i,1,n-2)
        {
            int l=i+1,r=n,sum=-a[i];
            while (l<r)
            {
                if (a[l]+a[r]==sum) 
                {
                    ans++;
                    l++;
                    r--;
                }
                else
                if (a[l]+a[r]>sum) r--;
                else l++;
            }
        }        	
        cout<<ans<<"\n";
    }
}
