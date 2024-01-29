#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
using ld = long double;
#define maxn 105
struct data{
    ld c,x,v;
} a[maxn];
bool cmp(data a,data b)
{
    return a.v>b.v;
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
        int n;
        ld w,ans=0;
        cin>>n>>w;
        FOR(i,1,n) cin>>a[i].c>>a[i].x, a[i].v=a[i].c/a[i].x;
        sort(a+1,a+1+n,cmp);
        FOR(i,1,n)
        {
            if (w>a[i].x) 
            {
                ans+=a[i].c;
                w-=a[i].x;
            }
            else 
            {
                ans+=w*a[i].v;
                break;
            }
        }
        cout<<fixed<<setprecision(2)<<ans<<"\n";
    }
}
