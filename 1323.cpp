#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 
string s;
unordered_map<int,int> mp;
void init()
{
    FOR(i,1,1000000) mp[i*i*i]=1;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>s;
        int n=s.length(),ans=-1;
        for (int mask=1;mask<(1<<n);mask++)
        {
            string t="";
            FOR(i,0,n-1) 
                if ((mask>>i)&1) t+=s[i];
            int tmp=stoll(t);
            if (mp[tmp] && tmp>ans) ans=tmp;
        }	
        cout<<ans<<"\n";
    }
}
