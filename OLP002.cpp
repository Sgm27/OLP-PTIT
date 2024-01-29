#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 
int l[4],w[4],maxl,maxw;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int S=0;
    FOR(i,0,3) cin>>l[i]>>w[i], maxl=max(maxl,l[i]), maxw=max(maxw,w[i]), S+=l[i]*w[i];
    int S1=(S/maxl+(S%maxl!=0))*maxl;
    int S2=(S/maxw+(S%maxw!=0))*maxw;
    cout<<min(S1,S2);
}
