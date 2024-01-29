#include<iostream>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int INF=9e18;
#define maxn 25
int mod,a[maxn];
inline int add(int a,int b,int M)
{
    int sum=a+b;
    if (sum<M) return sum;
    while (sum>=M) sum-=M;
    return sum;
}
int mul(int a,int b)
{
    int res=0;
    while (a>mod) a-=mod;
    while (b)
    {
        if (b & 1) res=add(res,a,mod);
        a=add(a,a,mod);
        b >>= 1ll;
    }
    return res;
}
int mul_mod(int a,int b,int MOD)
{
    int res=0;
    while (a>MOD) a-=MOD;
    while (b)
    {
        if (b & 1) res=add(res,a,MOD);
        a=add(a,a,MOD);
        b >>= 1ll;
    }
    return res;
}
struct matrix
{
    int val[maxn][maxn];
    int sz;
    matrix (int n)
    {
        sz=n;
        FOR(i,0,n)
            FOR(j,0,n) val[i][j]=0;
    }
    matrix operator * (matrix b)
    {
        matrix c(sz);
        for (int i=0;i<sz;i++)
            for (int j=0;j<sz;j++)
                for (int k=0;k<sz;k++)
                    c.val[i][j]=add(c.val[i][j],mul(val[i][k],b.val[k][j]),mod);
        return c;
    }
    matrix Pow(int k)
    {
        matrix c(sz);
        for (int i=0;i<sz;i++) c.val[i][i]=1;
        for (matrix i = (*this);k;i = i*i,k >>= 1ll)
            if (k & 1) c=c*i;
        return c;
    }
};
int Pow(int a, int n,int MOD)
{
    if (!n) return 1;
    if (n==1) return a;
    int tmp=Pow(a,n>>1ll,MOD);
    tmp=mul_mod(tmp,tmp,MOD);
    if (n%2) tmp=mul_mod(tmp,a,MOD);
    return tmp;
}
bool check(int d,int n)
{
    int a=rand()%(n-3)+2;
    int x=Pow(a,d,n);
    if (x==1 || x==n-1) return 1;
    while (d!=n-1)
    {
        x=mul_mod(x,x,n);
        d*=2;
        if (x==n-1) return 1;
    }
    return 0;
}
bool Miller(int n)
{
    if (n==2 || n==3) return true;
    if (n%2==0 || n%3==0) return false;
    if (n<5) return false;
    int d=n-1;
    while (d%2==0) d >>= 1ll;
    FOR(i,1,5)
        if (!check(d,n)) return 0;
    return 1;
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
        int n,k; cin>>n>>k>>mod;
        matrix ans(n+1);
        for (int i=0;i<n;i++) cin>>a[i];
        for (int i=0;i<n-1;i++)
            for (int j=i+1;j<n;j++)
            {
                if (Miller(6*a[i]+a[j])) ans.val[j][i]=1;
                if (Miller(6*a[j]+a[i])) ans.val[i][j]=1;
            }
        ans.val[n][n-1]=1;
        ans.val[n][n]=1;
        matrix base(n+1);
        for (int i=1;i<n;i++)
            if (Miller(6*a[0]+a[i])) base.val[i][0]=1;
        ans=ans.Pow(k);
        ans=ans * base;
        cout<<(ans.val[n][0])%mod<<"\n";
    }
}
