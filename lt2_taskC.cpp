#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 
struct ps{
    int tu,mau;
};
void rut_gon(ps &x)
{
    int G=__gcd(x.tu,x.mau);
    x.tu/=G;
    x.mau/=G;
}
int lcm(int a,int b)
{
    return a/__gcd(a,b)*b;
}
ps cong(ps a,ps b)
{
    int res=0;
    int mc=lcm(a.mau,b.mau);
    a.tu*=mc/a.mau;
    b.tu*=mc/b.mau;
    res=a.tu+b.tu;
    return {res,mc};
}
int Pow(int a, int n)
{
    if (!n) return 1;
    if (n==1) return a;
    int tmp=Pow(a,n/2);
    tmp=tmp*tmp;
    if (n%2) tmp=tmp*a;
    return tmp;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    cin>>s;
    ps x={1,1};
    ps ans={0,1};
    for (int i=s.length()-1;i>=0;i--)
    {
        if (i!=s.length()-1) 
        {
            x.mau*=2; 
            x.tu*=3;
        }
        ps a=x;
        a.tu*=(s[i]-'0');
        ans=cong(ans,a);
    }
    rut_gon(ans);
    if (ans.mau==1) cout<<ans.tu;
    else
    {
        cout<<ans.tu/ans.mau<<" ";
        ps x={ans.tu%ans.mau,ans.mau};
        rut_gon(x);
        cout<<x.tu<<"/"<<x.mau;
    }
}
