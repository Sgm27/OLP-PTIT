#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9,INF=9e18;
#define maxn 
string res[]={"03","13","51","93","23","01","83","33","51"};
struct T {
    int x,y;
};
T mod(T a)
{   
    a.x%=MOD;
    a.y%=MOD;
    return {a.x,a.y};
}
T Pow(T a,int n)
{
    if (n==1) return a;
    T tmp=Pow(a,n/2);
    int tx=tmp.x*tmp.x+3*tmp.y*tmp.y;
    int ty=2*tmp.x*tmp.y;
    tmp={tx,ty};
    tmp=mod(tmp);
    if (n%2) 
    {
        tx=2*tmp.x+3*tmp.y;
        ty=2*tmp.y+tmp.x;
        tmp={tx,ty};
        tmp=mod(tmp);
    }
    tmp=mod(tmp);
    return tmp;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    freopen("thu.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        if (!n)
        {
            cout<<"01\n";
            continue;
        }
        if (n<=9) 
        {
            cout<<res[n-1]<<"\n";
            continue;
        }
        T ans=Pow({2,1},n);
        int A=(ans.x*2-1+100*100)%100;
        if (A<10) cout<<"0"<<A<<"\n";
        else cout<<A<<"\n";
    }
}
