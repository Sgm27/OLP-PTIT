#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 105
int a[maxn],n,b[maxn],q,tmp[maxn];
vector<int> res;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,n) cin>>a[i];
    FOR(stt,1,q)
    {
        FOR(i,1,n) cin>>b[i], tmp[i]=a[i];
        FOR(i,1,n)
            FOR(j,1,n)
            {
                int x=__gcd(b[i],tmp[j]);
                if (x!=1)
                {
                    tmp[j]/=x;
                    b[i]/=x;
                }
            }
        bool flag=true;
        FOR(i,1,n)
            if (b[i]!=1) 
            {
                flag=false;
                break;
            }
        if (flag) res.push_back(stt);
    }
    cout<<res.size()<<"\n";
    for (int x : res) cout<<x<<" ";
}   
