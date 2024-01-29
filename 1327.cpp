#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD=1e9+7;
#define maxn 
void nhan(ll a[2][2],ll b[2][2])
{
    ll res[2][2];
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
        {
            res[i][j]=0;
            for (int k=0;k<2;k++) res[i][j]=(res[i][j]+a[i][k]*b[k][j])%MOD;
        }
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++) a[i][j]=res[i][j];
}
ll Pow(ll n)
{
    ll res[2][2]={{1,0},{0,1}};
    ll a[2][2]={{1,1},{1,0}};
    while (n!=0)
    {
        if (n%2==1)
            nhan(res,a);
        nhan(a,a);
        n/=2;
    }
    return res[0][1];
    // n+1 n
    // n   n-1
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        ll n;
        cin>>n;
        cout<<Pow(n)<<"\n"; 	
    }
}

