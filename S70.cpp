#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
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
        int n,k;
        cin>>n>>k;
        vector<int> a(n+1),ps(n+1);
        FOR(i,1,n) cin>>a[i], ps[i]=ps[i-1]+a[i];
        int l=1,r=1,flag=0,sum=0;
        while (r<=n)
        {
            sum+=a[r++];
            // cout<<l<<" "<<r<<" "<<sum<<"\n";
            while (l<=r && sum>k) sum-=a[l++];
            if (sum==k && r>l)
            {
                flag=1;
                break;
            }
        }        	
        cout<<(flag ? "YES\n" : "NO\n");
    }
}
