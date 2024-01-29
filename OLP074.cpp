#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define mp make_pair
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 205
int n,m,a[maxn];
vector<pii> adj[maxn];
map<pair<pii,pii>,int> visited;
struct data{
    int u1,u2,time;
};
int change(int i,int time)
{
    time%=3;
    int ans=(i+time)%3;
    if (!ans) return 3;
    return ans;
}
int bfs()
{
    queue<data> Q;
    Q.push({1,2,0});
    while (!Q.empty())
    {
        int u1=Q.front().u1;
        int u2=Q.front().u2;
        int time=Q.front().time;
        Q.pop();
        if (u1==u2) return time;
        for (pii v1 : adj[u1])
            if (change(v1.second,time) == a[u2])
            {
                for (pii v2 : adj[u2])
                    if (change(v2.second,time) == a[u1] && !visited[{{u1,v1.first},{u2,v2.first}}]) 
                    {
                        Q.push({v1.first,v2.first,time+1});
                        visited[{{u1,v1.first},{u2,v2.first}}]=1;
                    }
            }
    }
    return -1;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>m;
        FOR(i,1,n) adj[i].clear();
        visited.clear();
        FOR(i,1,n) cin>>a[i];
        FOR(i,1,m) 
        {
            int u,v,cl;
            cin>>u>>v>>cl;
            adj[u].push_back({v,cl});
        } 	
        cout<<bfs()<<"\n";
    }   
}
