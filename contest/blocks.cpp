#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 
int n,K;
void mul(int a[2][2],int b[2][2])
{
    int res[2][2];
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
        {
            res[i][j]=0;
            for (int k=0;k<2;k++) res[i][j]=(res[i][j]+a[i][k]*b[k][j])%K;
        }
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++) a[i][j]=res[i][j];
}
int Pow(int n)
{
    int res[2][2]={{1,0},{0,1}};
    int a[2][2]={{3,-1},{1,0}};
    while (n!=0)
    {
        if (n%2==1) mul(res,a);
        mul(a,a);
        n/=2;
    }
    return (res[1][0]*2+res[1][1]+K*K)%K;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>K;
    cout<<Pow((2*n-4)/2);
}
