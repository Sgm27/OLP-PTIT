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
        int n;
        cin>>n;
        if (n==1)
        {
            cout<<"1\n";
            continue;
        }
        vector<int> ans;
        FOD(j,9,2)
            while (n%j==0) 
            {
                ans.push_back(j);
                n/=j;
            }
        if (!ans.size() || n!=1)
        {
            cout<<"-1\n";
            continue;
        }
        reverse(ans.begin(),ans.end());
        for (int x : ans) cout<<x; cout<<"\n";
    }
}
