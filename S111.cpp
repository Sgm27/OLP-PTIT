#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005

int n,N,dp[maxn];
pii a[maxn];

struct Fenwick2d{
    vector<vector<int>> node,bit;
    int sz;
    void init(int n)
    {
        sz=n;
        node.resize(n+1);
        bit.resize(n+1);
    }
    void compressNode()
    {
        for(int i=1; i<=sz; i++)
        {
            sort(node[i].begin(),node[i].end());
            node[i].erase(unique(node[i].begin(),node[i].end()),node[i].end());
            bit[i].resize(node[i].size()+1);
        }
    }
    void fakeUpdate(int x, int y)
    {
        for(; x<=sz; x+=x&-x) node[x].push_back(y);
    }
    void fakeGet(int x, int y)
    {
        for(; x>0; x-=x&-x) node[x].push_back(y);
    }
    void update(int x, int yy, int val)
    {
        for(; x<=sz; x+=x&-x)
        {
            for(int y=lower_bound(node[x].begin(),node[x].end(),yy)-node[x].begin()+1; y<=node[x].size(); y+=y&-y)
            {
                bit[x][y-1]=max(bit[x][y-1],val);
            }
        }
    }
    int get(int x, int yy)
    {
        int res=0;
        for(; x>0; x-=x&-x)
        {
            for(int y=lower_bound(node[x].begin(),node[x].end(),yy)-node[x].begin()+1; y>0; y-=y&-y)
            {
                res=max(res,bit[x][y-1]);
            }
        }
        return res;
    }
} fw;
void compress(pii a[])
{
    vector<int> v;
    FOR(i,1,n) v.push_back(a[i].first);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    N=v.size();
    FOR(i,1,n)
        a[i].first=lower_bound(v.begin(),v.end(),a[i].first)-v.begin()+1;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n)
        cin>>a[i].first>>a[i].second;
    compress(a);
    fw.init(N);
    FOR(i,1,n)
    {
        fw.fakeUpdate(a[i].first,a[i].second);
        fw.fakeGet(a[i].first-1,a[i].second-1);
    }
    fw.compressNode();
    int ans=0;
    FOR(i,1,n)
    {
        dp[i]=fw.get(a[i].first-1,a[i].second-1)+1;
        fw.update(a[i].first,a[i].second,dp[i]);
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}   
