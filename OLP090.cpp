#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 
int n; 
string s;
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
        cin>>n>>s;
        int ans=0;
        for (int mask=0;mask<(1<<n);mask++)
        {
            string t="";
            for (int i=0;i<n;i++)
                if ((mask>>i)&1) t+='1';
                else t+='0';
            for (int i=0;i<=n-s.length();i++)
            {
                if (t.substr(i,s.length())==s) 
                {
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<"\n";
    }
}
