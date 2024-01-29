#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 105
int a[maxn],b[maxn],n,q;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> ans;
    cin>>n>>q;
    vector<int> t(n+1);
    FOR(i,1,n) cin>>a[i];
    int stt=0;
    while (q--)
    {
        stt++;
        FOR(i,1,n) cin>>b[i], t[i]=a[i];
        FOR(i,1,n)
            FOR(j,1,n)
            {
                int G=__gcd(b[i],t[j]);
                if (G!=1)
                {
                    b[i]/=G;
                    t[j]/=G;
                }
            }
        bool flag=true;
        FOR(i,1,n)
            if (b[i]!=1) 
            {
                flag=false;
                break;
            }
        if (flag) ans.push_back(stt);
    }
    cout<<ans.size()<<"\n";
    for (int x : ans) cout<<x<<" ";
}
