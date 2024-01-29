#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 105
int n,m,k;
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
                    (c.val[i][j]+=val[i][k]*b.val[k][j])%=MOD;
        return c;
    }
    matrix Pow(int k)
    {
        matrix c(sz);
        FOR(i,0,sz-1) c.val[i][i]=1;
        for (matrix i = (*this);k;i = i*i,k/=2)
            if (k & 1) c=c*i;
        return c;
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m>>k;
    matrix ans(n);
    FOR(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        u--, v--;
        ans.val[u][v]++;
    }
    ans=ans.Pow(k);
    int res=0;
    FOR(i,0,n-1)
        FOR(j,0,n-1) 
            res=(res+ans.val[i][j])%MOD;
    cout<<res;
}
