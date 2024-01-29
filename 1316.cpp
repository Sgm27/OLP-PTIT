#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 20

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
        char a[maxn];
        cin>>n;
        FOR(i,0,n-1) cin>>a[i];
        vector<string> ans;
        for (int mask=1;mask<(1<<n);mask++) 
        {
            string s="";
            FOR(i,0,n-1)
                if ((mask>>i)&1) s+=a[i];
            ans.push_back(s);
        }
        sort(ans.begin(),ans.end());
        for (string s : ans ) cout<<s<<" ";
        cout<<"\n";
    }    
}
