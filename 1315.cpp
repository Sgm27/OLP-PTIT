#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
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
        int n;
        cin>>n;
        vector<int> per(n);
        vector<vector<int>> all_per;
        FOR(i,0,n-1) per[i]=i+1;
        all_per.push_back(per);
        while (next_permutation(per.begin(),per.end()))
            all_per.push_back(per);
        reverse(all_per.begin(),all_per.end());
        for (auto v : all_per)
        {
            for (int x : v) cout<<x;
            cout<<" ";
        }
        cout<<"\n";
    }    
}
