#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 100005
int n,k,a[maxn],st[17][maxn];
int get(int l,int r)
{
    int t=log2(r-l+1);
    return __gcd(st[t][l],st[t][r-(1<<t)+1]);
}
void make_RMQ()
{
    FOR(i,1,n) st[0][i]=a[i];
    FOR(i,1,log2(n))
        FOR(j,1,n-(1<<i)+1)
            st[i][j]=__gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
bool f(int x)
{
    FOR(i,1,n-x+1)
        if (get(i,i+x-1)==k) return 1;
    return 0;
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
        bool flag=false;
        cin>>n>>k;
        FOR(i,1,n) 
        {
            cin>>a[i];
            if (a[i]==k) flag=true;
        }
        if (flag) 
        {
            cout<<"1\n";
            continue;
        }
        make_RMQ();
        int l=0,r=n;
        while (r-l>1)
        {
            int m=(r+l)/2;
            if (f(m)) r=m;
            else l=m;
        }
        if (f(r)) cout<<r<<"\n"; else cout<<"-1\n";
    }
}
