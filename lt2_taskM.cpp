#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
long double eps=1e-9;
#define maxn 100005
int n,a[maxn],st[18][maxn],ps[maxn];
int get(int l,int r)
{
    int k=log2(r-l+1);
    return min(st[k][l],st[k][r-(1<<k)+1]);
}
void make_RMQ()
{
    for (int i=1;i<=log2(n);i++)
	{
		for (int j=1;j<=(n-(1<<i)+1);j++)
		{
			st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i], st[0][i]=a[i], ps[i]=ps[i-1]+a[i];
    make_RMQ();
    long double ans=0;
    vector<int> idx;
    FOR(i,1,n-2)
    {
        int S=ps[n]-ps[i];
        long double tmp=1.0*(S-get(i+1,n))/(n-i-1);
        if (ans<tmp)
        {
            ans=tmp;
            idx.clear();
            idx.push_back(i);
        }
        else 
            if (abs(ans-tmp)<eps) idx.push_back(i);
    }
    for (int x : idx) cout<<x<<" ";
}
