#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 200005
int n,k,a[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    priority_queue<int,vector<int>,greater<int>> pq;
    FOR(i,1,n) cin>>a[i], pq.push(a[i]);
    int ans=0;
    while (pq.size()>1)
    {
        int Min=9e18,Max=0;
        int kk=k,sum=0;
        while (pq.size() && kk>0)
        {
            int x=pq.top();
            Min=min(Min,x);
            Max=max(Max,x);
            sum+=x;
            kk--;
            pq.pop();
        }
        pq.push(sum);
        ans+=(Max-Min);
    }
    cout<<pq.top()<<"\n"<<ans;
}
