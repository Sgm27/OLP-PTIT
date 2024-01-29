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
        priority_queue<int,vector<int>,greater<int>> pq;	
        FOR(i,1,n)
        {
            int x; cin>>x;
            pq.push(x);
        }
        int ans=0;
        while (pq.size()!=1)
        {
            int x1=pq.top();
            pq.pop();
            int x2=pq.top();
            pq.pop();
            pq.push(x1+x2);
            ans+=x1+x2;
        }
        cout<<ans<<"\n";
    }    
}
