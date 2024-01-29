#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1005
struct mang{
    int f,s;
} a[maxn];
int n;
bool cmp(mang a,mang b)
{
    return a.f<b.f;
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
        cin>>n;
        FOR(i,1,n) cin>>a[i].s;
        FOR(i,1,n) cin>>a[i].f;
        sort(a+1,a+1+n,cmp);
        int last_f=a[1].f,ans=1;
        FOR(i,2,n)
        {
            if (a[i].s>=last_f) 
            {
                ans++;
                last_f=a[i].f;
            }
        }
        cout<<ans<<"\n";
    }
}
