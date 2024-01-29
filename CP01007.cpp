#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
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
        int Max=-1;
        vector<int> v;
        cin>>n;
        FOR(i,1,n) cin>>a[i];
        FOD(i,n,1)
        {
            if (a[i]>Max) v.push_back(a[i]);
            Max=max(Max,a[i]);
        }
        reverse(v.begin(),v.end());
        for (int x : v) cout<<x<<" ";
        cout<<'\n';
    }
}
