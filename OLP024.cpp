#include<iostream>
#include<unordered_map>
#include<queue>
#include<string.h>
#include<time.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
#define max_bfs 1<<20
#define maxn 200
int n,m;
pii a[maxn];
int check[maxn][maxn],d[maxn];
vector<int> adj[maxn];
string s,t;
unordered_map<string,int> D,D1;
inline void bfs_back(string s)
{
    queue<string> Q;
    D[s]=0;
    Q.push(s);
    int cnt_bfs=0,step;
    while (!Q.empty())
    {
        if (++cnt_bfs>max_bfs) return;
        string x=Q.front();
        Q.pop();
        step=D[x];
        FOR(i,1,m)
        {
            swap(x[a[i].first-1],x[a[i].second-1]);
            if (!D[x] && check[x[a[i].second-1]-'a'+1][a[i].second] && check[x[a[i].first-1]-'a'+1][a[i].first]) 
            {
                D[x]=step+1;
                Q.push(x);
            }
            swap(x[a[i].first-1],x[a[i].second-1]);
        }
    }
}
inline int bfs_forward(string s)
{
    if (D[s]) return D[s];
    D1[s]=0;
    queue<string> Q;
    Q.push(s);
    int step;
    while (!Q.empty())
    {
        string x=Q.front();
        Q.pop();
        step=D1[x];
        FOR(i,1,m)
        {
            swap(x[a[i].first-1],x[a[i].second-1]);
            if (D[x]) return step+D[x]+1;
            if (!D1[x]) 
            {
                D1[x]=step+1;
                Q.push(x);
            }
            swap(x[a[i].first-1],x[a[i].second-1]);
        }
    }
}
void dfs(int u,int root)
{
    d[u]=1;
    for (int v : adj[u])
        if (!d[v]) 
        {
            check[root][v]=1;
            dfs(v,root);
        }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR(i,1,n) 
    {
        int c; cin>>c;
        s+=c+96;
        t+=i+96;
    }
    FOR(i,1,m) 
    {
        int u,v; cin>>u>>v;
        a[i].first=u, a[i].second=v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        check[u][v]=check[v][u]=1;
    }
    FOR(i,1,n)
    {
        memset(d,0,sizeof(d));
        check[i][i]=1;
        dfs(i,i);
    }
    if (s==t) return cout<<0, 0;
    bfs_back(t);
    cout<<bfs_forward(s);
    cerr<<"\n"<<TIME;
}