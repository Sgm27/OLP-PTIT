#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 25
int a[maxn][maxn];
void nhan(int a[2][2],int b[2][2])
{
    int res[2][2];
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
        {
            res[i][j]=0;
            for (int k=0;k<2;k++) (res[i][j]+=a[i][k]*b[k][j])%=MOD;
        }
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++) a[i][j]=res[i][j];
}
void Pow(int ans[maxn][maxn],int sz,int n)
{
    int res[maxn][maxn];
    memset(res,0,sizeof(res));
    FOR(i,1,sz) res[i][i]=1;
    int a[maxn][maxn]={{1,1},{1,0}};
    while (n!=0)
    {
        if (n%2==1)
        {
            nhan(res,a);
        }
        nhan(a,a);
        n/=2;
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

}
