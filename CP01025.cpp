#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 105
int n;
string s;
    //        |(1)
    // (2)---- ----(4)
    //        |(3)
pii calc(int i,int huong,int x,int y)
{
    if (i==n+1) return {x,y};
    if (huong==1)
    {
        if (s[i]=='G') return calc(i+1,1,x,y+1);
        if (s[i]=='B') return calc(i+1,3,x,y-1);
        if (s[i]=='R') return calc(i+1,4,x+1,y);
        if (s[i]=='L') return calc(i+1,2,x-1,y);
    }
    if (huong==2)
    {
        if (s[i]=='R') return calc(i+1,1,x,y+1);
        if (s[i]=='L') return calc(i+1,3,x,y-1);
        if (s[i]=='B') return calc(i+1,4,x+1,y);
        if (s[i]=='G') return calc(i+1,2,x-1,y);
    }
    if (huong==3)
    {
        if (s[i]=='B') return calc(i+1,1,x,y+1);
        if (s[i]=='G') return calc(i+1,3,x,y-1);
        if (s[i]=='L') return calc(i+1,4,x+1,y);
        if (s[i]=='R') return calc(i+1,2,x-1,y);
    }
    if (huong==4)
    {
        if (s[i]=='L') return calc(i+1,1,x,y+1);
        if (s[i]=='R') return calc(i+1,3,x,y-1);
        if (s[i]=='G') return calc(i+1,4,x+1,y);
        if (s[i]=='B') return calc(i+1,2,x-1,y);
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>s;
    s=" "+s;
    pii ans=calc(1,1,0,0);
    cout<<ans.first<<" "<<ans.second;
}
