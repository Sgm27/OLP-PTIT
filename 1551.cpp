#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 1000
int q,fw[1005][1005];
void update(int x,int y)
{
    for (int i=x;i<=maxn;i+=i&-i)
        for (int j=y;j<=maxn;j+=j&-j) fw[i][j]++;
}
int get(int x,int y)
{
    int ans=0;
    for (int i=x;i>0;i-=i&-i)
        for (int j=y;j>0;j-=j&-j) ans+=fw[i][j];
    return ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>q;
    while(q--)
    {
        int type; cin>>type;
        if (type==1)
        {
            int x,y;
            cin>>x>>y;
            update(x,y);
        }
        else
        {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            int n=get(c,d)-get(c,b-1)-get(a-1,d)+get(a-1,b-1);
            cout<<n*(n-1)*(n-2)/6<<"\n";
        }
    }
}
