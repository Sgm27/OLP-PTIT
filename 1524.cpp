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
        map<char,int> mp;
        int k,ans=0; string s;
        cin>>k>>s;
        for (char x : s) mp[x]++;
        priority_queue<int> pq;
        for (auto x : mp) pq.push(x.second);
        while (k)
        {
            int x=pq.top();
            pq.pop();
            k--;
            pq.push(x-1);
        }
        while (!pq.empty())
        {
            int x=pq.top();
            pq.pop();
            ans+=x*x;
        }
        cout<<ans<<'\n';
    }
}
