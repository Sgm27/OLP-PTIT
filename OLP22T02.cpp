#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 5005
int n,q;
int a[maxn];
long long g[5005][5005];
short D[6000006];
int delta=3e6+5;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,n) cin>>a[i];
    int idx=q;
    FOR(i,1,n-2)
    {
       // D.clear();
        D[a[i+1]+delta]++;
        for (int l=i+2;l<=n;l++)
        {
            if (D[-a[i]-a[l]+delta]) 
            {
            	g[i][l]+=D[-a[i]-a[l]+delta];
            }
            D[a[l]+delta]++;
        }
        for (int l=i+1;l<=n;l++)
          D[a[l]+delta]--;
    } 
    for (int i=1;i<=n;i++)
    for (int j=i;j<=n;j++)
    g[i][j]=g[i][j-1]+g[i][j];
    
    for (int j=1;j<=n;j++)
    for (int i=1;i<=j;i++)
    g[i][j]=g[i-1][j]+g[i][j];
	
	for (int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		cout<<g[r][r]-g[l-1][r]<<"\n";
	}
    
}
