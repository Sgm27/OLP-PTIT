#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD=1e9+7;
#define maxn 15
ll a[maxn][maxn],n,k,res[maxn][maxn];
void mul(ll a[15][15],ll b[15][15])
{
    ll res[15][15];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            res[i][j]=0;
            for (int k=1;k<=n;k++) 
                res[i][j]=(res[i][j]+a[i][k]*b[k][j])%MOD;
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) a[i][j]=res[i][j];
}
void process()
{
    for (int i=1;i<=n;i++) res[i][i]=1;
    while (k)
    {
        if (k%2) mul(res,a);
        mul(a,a);
        k/=2;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++) cout<<res[i][j]<<" ";
        cout<<"\n";
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>k;
        for (int i=1;i<=n;i++) 
            for (int j=1;j<=n;j++) 
            {
                cin>>a[i][j];
                res[i][j]=0;
            }
        process();
    }
}

