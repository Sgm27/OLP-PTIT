#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 1005
int n,k,fac[maxn],inv_fac[maxn];

int Pow(int a, int n)
{
    if (!n) return 1;
    if (n==1) return a;
    int tmp=Pow(a,n/2)%MOD;
    tmp=tmp*tmp%MOD;
    if (n%2) tmp=tmp*a%MOD;
    return tmp;
}
void init()
{
    fac[0]=inv_fac[0]=1;
    FOR(i,1,maxn-5)
    {
        fac[i]=(fac[i-1]*i)%MOD;
        inv_fac[i]=Pow(fac[i],MOD-2);
    }
}
int P(int k,int n)
{
    if (k>n) return 0;
    int fac_n=fac[n];
    int inv=inv_fac[n-k];
    return (fac_n*inv)%MOD;
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
        cin>>n>>k;
        cout<<P(k,n)<<"\n";
    }
}
