#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 100005
vector<int> adj[maxn];
int n,m;
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>m;
        FOR(i,1,n) adj[i].clear();
        FOR(i,1,m) 
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }	
        bool flag=true;
        FOR(i,1,n)
        {
            for (int v : adj[i])
                if (adj[v].size()!=adj[i].size()) 
                {
                    flag=false;
                    break;
                }
            if (!flag) break;
        }
        if (flag) cout<<"YES\n"; else cout<<"NO\n";
    }
}
