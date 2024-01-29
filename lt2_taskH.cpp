#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 
int a,b,c,d,k,step;
int dx,dy;
bool check()
{
    int sx=0,sy=0;
    sy+=a;
    if (sy>=k) return cout<<step+k, true;
    step+=a;
    sx+=b;
    if (sx>=k) return cout<<step+k, true;
    step+=b;
    if (sy-c<=-k) return cout<<step+(k+sy), true;
    sy-=c;
    step+=c;
    if (sx-d<=-k) return cout<<step+(k+sx), true;
    sx-=d;
    step+=d;
    dx=sx, dy=sy;
    return false;
}
bool f(int x)
{
    int tx=dx*x;
    int ty=dy*x;
    if (tx<=-k || tx>=k || ty>=k || ty<=-k) return true;
    return false;
}
bool in(int x,int y)
{
    if (x>-k && x<k && y>-k && y<k) return 1;
    return 0;
}
int back_path(int x,int y,int ans_step)
{
    int ans=INF;
    x+=d;
    if (in(x,y)) return ans_step-d+abs(-k-x);
    ans_step-=d;
    y+=c;
    if (in(x,y)) return ans_step-c+abs(-k-y);
    ans_step-=c;

    x-=b;
    if (in(x,y)) return ans_step-b+abs(k-x);
    ans_step-=b;
    y-=a;
    if (in(x,y)) return ans_step-a+abs(k-y);
    ans_step-=a;
    return ans;
}
bool Check(int x,int y)
{
    y+=a;
    if (!in(x,y)) return 1;
    x+=b;
    if (!in(x,y)) return 1;
    y-=c;
    if (!in(x,y)) return 1;
    x-=d;
    if (!in(x,y)) return 1;
    return 0;
}
int forward_path(int x,int y,int ans_step)
{
    if (!in(x,y+a)) return ans_step+(k-y);
    y+=a;
    ans_step+=a;
    if (!in(x+b,y)) return ans_step+(k-x);
    x+=b;
    ans_step+=b;
    if (!in(x,y-c)) return ans_step+(y+k);
    y-=c;
    ans_step+=c;
    if (!in(x-d,y)) return ans_step+(x+k);
    x-=d;
    ans_step+=d;
    return INF;
}
void process()
{
    int l=0,r=1e10;
    while (r-l>1)
    {
        int m=(l+r)/2;
        if (f(m)) r=m;
        else l=m;
    }
    step=a+b+c+d;
    int ans=INF;
    FOR(i,-1,4)
    {
        int x=dx*(max(0ll,r-i));
        int y=dy*(max(0ll,r-i));
        ans=min(ans,forward_path(x,y,step*max(0ll,r-i)));
    }
    cout<<ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>a>>b>>c>>d>>k;
    if (check()) return 0;
    else
        process();
}
