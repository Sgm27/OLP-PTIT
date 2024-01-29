#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 

int lcm(int x,int y)
{
    return x/__gcd(x,y)*y;
}
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
        int x,y;
        cin>>x>>y;
        int prod=1;
        FOR(i,x,y) prod*=i;
        cout<<prod<<"\n";
        int count =0 ;
        FOR(i,1,150)
            FOR(j,1,150) 
                if (lcm(i,j)==prod) 
                {
                    count++;
                    cout<<i<<" "<<j<<"\n"; 	
                }
        cout<<count;
    }
}
