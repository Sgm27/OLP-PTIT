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
        string s;
        int ans=0;
        cin>>s;
        for (int i=0;i<s.length();i++)
            for (int j=1;j<=s.length()-i;j++)
            {
                string t=s.substr(i,j);
                ans+=stoll(t);
            }   	
        cout<<ans<<"\n";
    }    
}
