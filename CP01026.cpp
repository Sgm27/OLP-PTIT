#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
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
    int x,y;
    while (cin>>x>>y)
    {
        int d=abs(x-y);
        int S=sqrt(d)-1;
        while (S*(S+1)<d) S++;
        if (S*(S+1)-d<S) cout<<S*2<<'\n';
        else cout<<S*2-1<<"\n";
    }
}
