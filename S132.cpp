#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll chinh[405][405],phu[405][405],n,a[405][405];
void input()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)  cin>>a[i][j];
}
void init()
{
    for (int i=0;i<=n+1;i++) 
    {
        chinh[0][i]=0;
        phu[0][i]=0;
        chinh[i][0]=0;
        phu[i][n+1]=0;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            chinh[i][j]=0;
            phu[i][j]=0;
            chinh[i][j]=chinh[i-1][j-1]+a[i][j];
            phu[i][j]=phu[i-1][j+1]+a[i][j];
        }
}
void process()
{
    ll res=-1e18;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            int t=min(i,j);
            for (int len=1;len<=t-1;len++)
            {
                ll sum_chinh=chinh[i][j]-chinh[i-len-1][j-len-1];
                ll sum_phu=phu[i][j-len]-phu[i-len-1][j+1];
                res=max(res,sum_chinh-sum_phu);
            }
        }
    cout<<res;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    init();
    process();
}

