#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 
struct Fenwick2D{
    vector<vector<int>> t;
    int n;
    Fenwick2D(int sz)
    {
        n=sz;
        t.resize(sz+1,vector<int>(sz+1));
    }
    void update(int x,int y)
    {
        for (int i=x;i<=n;i+=i&-i)
            for (int j=y;j<=n;j+=j&-j) t[i][j]++;
    }
    int get(int x,int y)
    {
        int ans=0;
        for (int i=x;i>0;i-=i&-i)
            for (int j=y;j>0;j-=j&-j) ans+=t[i][j];
        return ans;
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    Fenwick2D fw(1000);
    int q; cin>>q;
    while (q--)
    {
        int type; cin>>type;
        if (type==1)
        {
            int u,v; cin>>u>>v;
            fw.update(u,v);
        }
        else
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            int count=fw.get(x2,y2)-fw.get(x1-1,y2)-fw.get(x2,y1-1)+fw.get(x1-1,y1-1);
            cout<<count*(count-1)*(count-2)/6<<"\n";
        }
    }
}
